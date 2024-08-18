#include <iostream>
#include <unistd.h>
#include <thread>   // for std::this_thread::sleep_for
#include <chrono>   // for std::chrono::seconds
#include <cstring>
#include <cstdio>
#include "elevator/elevator.h"
#include "comm/send_recv_fd.h"
#include "comm/client.h"

#define BUFFER_SIZE 50
void handle_input(tsung_bao::elevator& elevator){
    char input[BUFFER_SIZE] = {0} ; 
    while(1){
        scanf("%s", input) ;
        if(strcmp(input,"1") == 0){
            elevator.enter(1) ; 
        }else if(strcmp(input,"2") == 0){
            elevator.enter(2) ; 
        }else if(strcmp(input,"up") == 0){
            elevator.enter(3) ; 
        }else if(strcmp(input,"down") == 0){
            elevator.enter(4) ; 
        }else{
            printf("Invalid input. Please enter 1, 2, up, down \n") ;
        }
    }
}


int main(){
    // 1. Fork `print_msg`.
    int pipe_fds[2] ; 
    pipe(pipe_fds) ; 

    pid_t pid = -1 ;
    pid = fork() ; 
    
    if(pid == 0){
        // Child process
        close(pipe_fds[0]) ;  // Close the read end of the pipe

        char write_pipe_fd[BUFFER_SIZE] = {0};
        // Convert int to string
        sprintf(write_pipe_fd, "%d", pipe_fds[1]);

        const char* args[3] = {"./print_msg", (const char*) write_pipe_fd
                                        ,  NULL} ;
         
        execvp(args[0],(char* const*)args) ;
        
        std::cerr << "*** Fork print_msg failed *** \n";
        exit(-1) ; 
    }
    

    close(pipe_fds[1]) ; // Close the write end of the pipe

    char mesg_from_print_msg[BUFFER_SIZE] = {0};
    
    // 2. Block until print_msg send "r\n" (meaning server is ready) via pipe, 
    //    indicating that the server is ready.
    tsung_bao::read_oneline(pipe_fds[0], mesg_from_print_msg, sizeof(mesg_from_print_msg)) ;

    if(strcmp(mesg_from_print_msg,"r\n") != 0){
        std::cerr << "*** print_msg should have sent \" r\\n \" to main***\n" ;
        exit(-1) ; 
    }

    memset(mesg_from_print_msg, '\0', sizeof(mesg_from_print_msg)) ;

    // port number being sent. mesg_from_print_msg = "19975\n" ;
    tsung_bao::read_oneline(pipe_fds[0], mesg_from_print_msg, sizeof(mesg_from_print_msg)) ;
    mesg_from_print_msg[strlen(mesg_from_print_msg)-1] = '\0' ;
    std::cout << "opened port: " << mesg_from_print_msg << std::endl ;
    // 3. Close read pipe
    close(pipe_fds[0]) ;

    int port_num = atoi(mesg_from_print_msg);
    
    int client_communication_fd 
        = tsung_bao::client_connect("127.0.0.1",port_num) ;
    
    if(client_communication_fd == -1){
	std::cerr << "main (client) connect to print_msg (server) failed." << std::endl ;
        exit(-1) ; 
    }

    // 4. Create an elevator instance.
    tsung_bao::elevator elevator(5,2) ;

    // 5. Create a new thread (input_thread) to handle input.
    //    The elevator instance should be passed as argument.
    std::thread input_thread(handle_input, std::ref(elevator)) ;
    input_thread.detach();

    // 6. The main thread doesn't wait for input_thread.
    //    The main thread keeps sending the state of the elevator 
    //    instance to `print_msg` (server.)
     
    char state_str[BUFFER_SIZE] = {0} ; 
    while(1){
        elevator.operation() ; 
        elevator.show_state(state_str) ; 
        strcat(state_str,"\n") ;
	    tsung_bao::write_oneline(client_communication_fd,state_str) ;       
        std::this_thread::sleep_for(std::chrono::seconds(1)); 
    }
    

    return 0 ;
}
