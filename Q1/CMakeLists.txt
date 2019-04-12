cmake_minimum_required(VERSION 3.13)
project(Q1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Q1
        main.cpp
        MaxHeap.cpp
        MaxHeap.h)
