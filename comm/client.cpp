#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "client.h"

// ip: "xx.xx.xx.xx"
// Return communication_fd
// Return -1 when something went wrong
int tsung_bao::client_connect(const char* ip, const int port){

    int communication_fd = socket(PF_INET,SOCK_STREAM,0) ;

    struct sockaddr_in name ;
    name.sin_family = AF_INET ; // 1
    inet_aton(ip,&(name.sin_addr));  // 2
    name.sin_port = htons(port) ; // 3

    if(connect(communication_fd,(struct sockaddr*) &name, sizeof(struct sockaddr_in)) == -1){
        std::cerr << "*** Client connection faliure. ***\n" ;
        return -1 ;
    }

    return communication_fd ;
}
