cmake_minimum_required(VERSION 4.3)
project(PigDie2)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(PigDie2
        main.cpp
        DIE.h
        DIE.cpp)
