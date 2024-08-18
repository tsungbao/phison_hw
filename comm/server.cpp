#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include "server.h"

// Retrun server_socket file descriptor
int tsung_bao::create_server(int* opened_port){
    // 1. Create socket
    int server_socket_fd = socket(PF_INET, SOCK_STREAM, 0);

    // 2. Fill in server_address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    inet_aton("127.0.0.1",&(server_address.sin_addr));
    
    // 3. Bind socket with server_address’s IP address and port number
    int bind_val = -1 ;
    int listen_val = -1 ;
    while(bind_val == -1 || listen_val == -1){
        bind_val = bind(server_socket_fd, (struct sockaddr*)&server_address
                        , sizeof(server_address));
   
        // 4. Listen for incoming connections
        listen_val = listen(server_socket_fd, 10);   // Max 10 connection queued
    }
    std::cout << "print_msg: " << ntohs(server_address.sin_port) << std::endl ;  
    *opened_port = ntohs(server_address.sin_port) ; 

    return server_socket_fd ; 
}

// Return communication file descriptor
int tsung_bao::my_accept(int server_socket_fd){
                // In this case, we don't care about client socket address.
                // Therefore, the second and the third arguments are filled
                // with NULL. 
    return accept(server_socket_fd, NULL, NULL) ; 
}
