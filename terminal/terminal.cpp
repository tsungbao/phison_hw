#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include "terminal.h"

int tsung_bao::launch_term_set_stdout(){
   	/*
		The posix_openpt() function opens an unused pseudoterminal master
		device, returning a file descriptor that can be used to refer to
		that device.

    	O_RDWR Open the device for both reading and writing. It is usual
      	to specify this flag.
   */
	int master_device = posix_openpt(O_RDWR);
	if (master_device == -1){
		std::cerr << "*** Could not open pseudo terminal. *** \n";
		return -1;
	}
	/*
		The ptsname() function returns the name of the slave
		pseudoterminal device corresponding to the master referred to by
		the file descriptor fd.
	*/
	char* slave_name = ptsname(master_device);
	if (!slave_name){
		std::cerr << "*** Could not get pseudo terminal device name. ***\n";
		close(master_device);
		return -1;
	}
	/*
		The unlockpt(fd) function unlocks the slave pseudoterminal device
       	corresponding to the master pseudoterminal referred to by the
       	file descriptor fd.

		unlockpt() should be called before opening the slave side of a
       	pseudoterminal.
	*/

	if (unlockpt(master_device) == -1){
		std::cerr << "*** Could not get pseudo terminal device name. ***\n";
		close(master_device);
		return -1;
	}

	// Associate a xterm process with slave and master
	std::ostringstream oss;
	oss << "xterm -S" << (strrchr(slave_name, '/')+1) 
						<< "/" << master_device << " -fn 10x20 &";
	system(oss.str().c_str());

	int xterm_fd = open(slave_name,O_RDWR);

	if(xterm_fd == -1){
		std::cerr << "*** Could not associate . ***\n";
		close(master_device);
		return -1;
	}

	if (dup2(master_device, 1) <0){
		std::cerr << "Could not redirect standard output.\n";
		close(master_device);
		return -1;
	}

}

