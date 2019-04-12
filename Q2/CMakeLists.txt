cmake_minimum_required(VERSION 3.13)
project(Q2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Q2
        dVector.cpp
        dVector.h
        main.cpp)
