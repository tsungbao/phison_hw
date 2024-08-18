# Testing Environment
Ubuntu 22.04 LTS

# To run the code

## Prerequisites
`xterm`: `sudo apt-get -y install xterm`

## Executable
`build/main`

## Build process
If running `build/main` doesn't work, please build the program own your own.

1. Run `cmake -S . -B ./build`. 
2. In `build/`, run `make`.
3. Executable `build/main` is created.

# Demo

Please refer to `phison_hw_screencast.webm`

# Description
1. `main` receives input.
2. `main` processes input, and change the state of the elevator if necessary.
3. Every second, `main` send the state of the elevator to `print_msg` via socket.
4. `print_msg`'s stdout is redirected to a seperate pseudo terminal `xterm`.
5. The state of the elevator in each second will printed on the psuedo terminal created by `print_msg`. 

```
                                        main
                                        |
                    print_msg   <-fork  |
(print_msg's stdout)    |               |
        xterm  <-fork   |               |
          |             |               |
          |             |               |
          |  <-redirect |               |
          |    stdout   |               |
          |             |               |  <- stdin
          |             |               |  (processing)
          |  <-stdout   |   <-socket    |          
```
                        