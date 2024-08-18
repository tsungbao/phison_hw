#ifndef SEND_RECV_FD_H
#define SEND_RECV_FD_H
#include <cstdio>
namespace tsung_bao{
    // The last character being read should be '\n'
    // Return -1 if something went wrong    
    int read_oneline(int communication_fd, char* buffer, size_t buffer_size) ;
    
    // Make sure that the last character is '\n'
    // Return -1 if something went wrong
    int write_oneline(int communication_fd, const char* message) ; 

}

#endif
