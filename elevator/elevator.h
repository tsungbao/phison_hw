#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <mutex>
namespace tsung_bao{
    class elevator{
        enum state{
            ONE_IDLE,
            ONE_OPEN,
            UP,
            DOWN,
            TWO_IDLE,
            TWO_OPEN
        } state ;
                    // 1, 2, up, down
        bool operations[4] = {0} ;

        // Remaining time (in seconds) for the elevator going up or down.
        // During this period of time, the state of the elevator shouldn't
        // be changed. 
        int cur_uping_downing_cnt = 0 ; 
         
        int max_up_down_cnt = 5 ; // In our case, 5 (5 seconds.)    
        
        int cur_open_cnt = 0 ; 
        int max_open_cnt = 2 ; // In our case, open for 2 seconds.

        std::mutex operations_mut ; 
    public:
        elevator() = default ;
        elevator(int max_up_down_cnt, int max_open_cnt);    
        elevator(const elevator& that) = default ;
        elevator& operator=(const elevator& that) = default ;

        // Ignore move constructor and move assignment for simplcity
        elevator(elevator&& that)= delete ; 
        elevator& operator=(elevator&& that) = delete ; 

        // >>> handled by input_thread >>>     
        void enter(int input) ; // 1, 2, up, down
        // <<< handled by input_thread <<<   

        // >>> handled by main thread >>>   
        void operation();
        void show_state(char* state);
        // <<< handled by main thread <<<   
    }; 
}
#endif

