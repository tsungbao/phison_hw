#ifndef TERMINAL_H
#define TERMINAL_H
namespace tsung_bao{
    // Lanch a new xterm terminal and change STDOUT to such 
    // terminal.
    // Return -1 when something went wrong.
    int launch_term_set_stdout() ; 
}

#endif