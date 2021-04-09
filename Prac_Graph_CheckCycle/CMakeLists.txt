cmake_minimum_required(VERSION 3.17)
project(Prac_Question2_CheckCycle)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Prac_Question2
        driver_graph.cpp
        graph.cpp
        graph.h)
