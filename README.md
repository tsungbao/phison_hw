# Testing Environment
Ubuntu 22.04 LTS

# To run the code

## Prerequisites
`xterm`: `sudo apt-get -y install xterm`

## Executable
`src/build/main`

## Build process
If running `src/build/main` doesn't work, please build the program own your own.

1. In `src`, run `cmake -S . -B ./build`. 
2. In `src/build`, run `make`.
3. Executable `src/build/main` is created.

# Demo

Please refer to `phison_hw_screencast.webm`

# Description
```
                                        main
                                        |
                    print_msg   <-fork  |
(print_msg's stdout)    |               |
        xterm           |               |
          |   <-fork    |               |
          |             |               |
          |  <-redirect |               |
          |    stdout   |               |
          |             |               |  <- stdin
          |             |               |  (processing)
          |  <-stdout   |   <-socket    |          
```
                        