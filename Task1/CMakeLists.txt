cmake_minimum_required(VERSION 3.27)
project(Task1 C)

# added -fopenmp
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")

set(CMAKE_C_STANDARD 99)

add_executable(Task1 main.c seidel.c seidel.h
        utils.c
        utils.h)
