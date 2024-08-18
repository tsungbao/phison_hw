#include <iostream>
#include <cstring>
#include <thread>   // for std::this_thread::sleep_for
#include <chrono>   // for std::chrono::seconds
#include "elevator.h"

tsung_bao::elevator::elevator(int max_up_down_cnt, int max_open_cnt){
    this->max_up_down_cnt = max_up_down_cnt ; 
    this->max_open_cnt = max_open_cnt ; 
    this->state = tsung_bao::elevator::state::ONE_IDLE ;
}

void tsung_bao::elevator::enter(int input){
    this->operations_mut.lock() ; 
    switch(input){
        case 1:
            this->operations[0] = true ;
            break ;
        case 2:
            this->operations[1] = true ;
            break ;
        case 3: //up
            this->operations[2] = true ;
            break ;
        case 4: //down
            this->operations[3] = true ;
            break ;
        default:
            // Invalid input
            std::cerr << "Invalid input" << std::endl ;
            break ;
    }
    this->operations_mut.unlock() ; 
}

void tsung_bao::elevator::show_state(char* state){
    switch(this->state){
        case tsung_bao::elevator::state::ONE_IDLE:
            strcpy(state,"ONE IDLE");
            break ;
        case tsung_bao::elevator::state::ONE_OPEN:
            strcpy(state,"ONE OPEN");
            break ;
        case tsung_bao::elevator::state::UP:
            strcpy(state,"UP");
            break ;
        case tsung_bao::elevator::state::TWO_IDLE:
            strcpy(state,"TWO IDLE");
            break ;
        case tsung_bao::elevator::state::TWO_OPEN:
            strcpy(state,"TWO OPEN");
            break ;
        case tsung_bao::elevator::state::DOWN:
            strcpy(state,"DOWN");
            break ;
    }
}

void tsung_bao::elevator::operation(){
    this->operations_mut.lock() ;
    switch(this->state){

        case tsung_bao::elevator::state::ONE_IDLE: 
                    // 1           up
            if(this->operations[0] || this->operations[2]){
                this->operations[0] = false ; 
                this->operations[2] = false ;
                this->cur_open_cnt = this->max_open_cnt ; 
                this->state = tsung_bao::elevator::state::ONE_OPEN ;  
                // Note that if you press up and 1 simultaneously,
                // the door will open only once, and buttons 1 and up
                // will be cleared.
            }else if(this->operations[1] || this->operations[3]){
                          // 2                down
                this->operations[1] = false ; 
                this->operations[3] = false ;
                this->cur_uping_downing_cnt = this->max_up_down_cnt ;   
                this->state = tsung_bao::elevator::state::UP ; 
            }
            break ;
        
        case tsung_bao::elevator::state::ONE_OPEN: 
            // 1                up
            if(operations[0] || operations[2]){
                // Reset the timer.
                this->cur_open_cnt = this->max_open_cnt ; 
                operations[0] = false ; 
                operations[2] = false ;
            }else{
                if(--this->cur_open_cnt <= 0){
                    this->state = tsung_bao::elevator::state::ONE_IDLE ;
                }
            }

            break ;

        case tsung_bao::elevator::state::UP:
            if(--this->cur_uping_downing_cnt <= 0){
                this->cur_open_cnt = this->max_open_cnt ; 
                this->state = tsung_bao::elevator::state::TWO_OPEN ; 
            }
            break;

        case tsung_bao::elevator::state::DOWN:
            if(--this->cur_uping_downing_cnt <= 0){
                this->cur_open_cnt = this->max_open_cnt ; 
                this->state = tsung_bao::elevator::state::ONE_OPEN ; 
            }
            break ;
        
        case tsung_bao::elevator::state::TWO_IDLE:
                    // 2                 down
            if(this->operations[1] || this->operations[3]){
                this->operations[1] = false ; 
                this->operations[3] = false ;
                this->cur_open_cnt = this->max_open_cnt ; 
                this->state = tsung_bao::elevator::state::TWO_OPEN ;  
                // Note that if you press down and 2 simultaneously,
                // the door will open only once, and both buttons 2 and 
                // down will be cleared.
            }else if(this->operations[0] || this->operations[2]){
                          // 1                up
                this->operations[0] = false ; 
                this->operations[2] = false ;  
                this->cur_uping_downing_cnt = this->max_up_down_cnt ;   
                this->state = tsung_bao::elevator::state::DOWN ; 
            }
            break ;
        
        case tsung_bao::elevator::state::TWO_OPEN:
                    // 2                down
            if(operations[1] || operations[3]){
                // Reset the timer.
                this->cur_open_cnt = this->max_open_cnt ; 
                operations[1] = false ; 
                operations[3] = false ;
            }else{
                if(--this->cur_open_cnt <= 0){
                    this->state = tsung_bao::elevator::state::TWO_IDLE ;
                }
            }
            break ;
    }

    this->operations_mut.unlock() ; 
}
