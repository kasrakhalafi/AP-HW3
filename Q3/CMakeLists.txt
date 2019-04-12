cmake_minimum_required(VERSION 3.13)
project(Q3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Q3
        Human.cpp
        Human.h
        main.cpp)
