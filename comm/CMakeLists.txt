cmake_minimum_required(VERSION 3.22.1)
project(comm)
add_library(client SHARED client.cpp)
set_target_properties(client PROPERTIES PUBLIC_HEADER client.h)

add_library(server SHARED server.cpp)
set_target_properties(server PROPERTIES PUBLIC_HEADER server.h)

add_library(send_recv_fd SHARED send_recv_fd.cpp)
set_target_properties(send_recv_fd PROPERTIES PUBLIC_HEADER send_recv_fd.h)
