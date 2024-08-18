cmake_minimum_required(VERSION 3.22.1)
project(terminal)
add_library(terminal SHARED terminal.cpp)
set_target_properties(terminal PROPERTIES PUBLIC_HEADER terminal.h)
