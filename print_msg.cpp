#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include "comm/server.h"
#include "comm/send_recv_fd.h"
#include "terminal/terminal.h"

#define BUFFER_SIZE 50

                // argv[] = { "print_mesg", "3" (write pipe fd) }
int main(int argc, char* argv[]){

    // 1. Create a new pseudo terminal, and set STDOUT to such terminal.
    int launched = tsung_bao::launch_term_set_stdout() ;
    if(launched == -1){
        std::cerr << "*** Launch pseudo terminal failed ***\n" ;
        exit(-1) ; 
    }


    // 2. Create server
    int opened_port = 0 ; 
    int server_socket_fd = tsung_bao::create_server(&opened_port) ;

    std::cout << "print_mesg: opened port: " << opened_port << std::endl;  
    
    // 3. Notify `main` that the server is ready.
    char write_back_to_main[BUFFER_SIZE] = {0} ;
    sprintf(write_back_to_main,"%d\n", opened_port) ;
    
    int write_pipe_fd = atoi(argv[1]) ;
    tsung_bao::write_oneline(write_pipe_fd, "r\n") ;
    tsung_bao::write_oneline(write_pipe_fd,write_back_to_main) ; 


    // 4. Accept a connection (In this case, I don't think we need a while loop to accept multiple 
    //    connections.)
    int communication_fd = tsung_bao::my_accept(server_socket_fd) ;

    // 5. Close write pipe.
    close(atoi(argv[1])) ;

    // 6. Whenever a string arrives via the communication_fd, send it to STDOUT, which has 
    //    been changed to the new pseudo terminal.
    char buffer[BUFFER_SIZE] = {0} ;
    while(true){
        tsung_bao::read_oneline(communication_fd, buffer, sizeof(buffer)) ;
        std::cout << buffer ;
        memset(buffer,'\0',sizeof(buffer)) ;	
    }

    return 0 ; 
}
