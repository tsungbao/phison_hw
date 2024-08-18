#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/ioctl.h>
#include "send_recv_fd.h"

// The last character being read should be '\n'
// Return -1 if something went wrong 
int tsung_bao::read_oneline(int communication_fd, char* buffer, size_t buffer_size) {
    
    ssize_t bytes_read = 0 ;
    // Read one character at a time, and return when reading in '\n'. 
    while(true){
        ssize_t tmp = read(communication_fd
                                    , buffer + bytes_read, 1) ;
        if(tmp == -1){
            std::cerr << "*** Something went wrong while reading ***" << std::endl ;
            return -1 ;
	    }
	
	    bytes_read += tmp ;
        if(buffer[bytes_read-1] == '\n'){
            break ;
        } 
    }
	
    return bytes_read ;
}

// Make sure that the last character is '\n'
// Return -1 if something went wrong
int tsung_bao::write_oneline(int communication_fd, const char* message){

    ssize_t size_to_be_sent = (ssize_t) strlen(message) ;
    
    if(message[size_to_be_sent-1] != '\n'){
    	std::cerr << "*** Message being sent should end with \\n  ***" << std::endl ;
    	return -1 ;
    }

    ssize_t bytes_written = 0 ;
    while(bytes_written < size_to_be_sent){
        ssize_t tmp = write(communication_fd,
                                message + bytes_written ,
                                size_to_be_sent - bytes_written) ;
    	if(tmp == -1){
	    std::cerr << "*** Something went wrong while writing ***" << std::endl ;
	    return -1 ;
	}
	bytes_written += tmp ;
    }
    return bytes_written ;
}
