cmake_minimum_required(VERSION 3.22.1)
project(elevator)
add_library(elevator SHARED elevator.cpp)
set_target_properties(elevator PROPERTIES PUBLIC_HEADER elevator.h)
