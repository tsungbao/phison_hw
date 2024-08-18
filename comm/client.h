#ifndef CLIENT_H
#define CLIENT_H
namespace tsung_bao{
    // ip: "xx.xx.xx.xx"
    // Return communication_fd
    // Return -1 when something went wrong
    int client_connect(const char* ip, const int port) ; 
}

#endif