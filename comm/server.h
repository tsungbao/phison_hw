#ifndef SERVER_H
#define SERVER_H
namespace tsung_bao{
    // Retrun server_socket file descriptor
    // Return -1 when something went wrong
    int create_server(int* opened_port);

    // Return communication file descriptor
    // Return -1 when something went wrong
    int my_accept(int server_socket_fd) ; 
}

#endif


