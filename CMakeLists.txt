cmake_minimum_required(VERSION 3.22.1)
project(src)

add_subdirectory(comm ../comm/build)
add_subdirectory(terminal ../terminal/build)
add_subdirectory(elevator ../elevator/build)

add_executable(main main.cpp)
add_executable(print_msg print_msg.cpp)

target_link_directories(main PRIVATE ./comm/build PRIVATE ./elevator/build)
target_link_libraries(main client send_recv_fd elevator)

target_link_directories(print_msg PRIVATE ./comm/build PRIVATE ./terminal/build)
target_link_libraries(print_msg server send_recv_fd terminal)
