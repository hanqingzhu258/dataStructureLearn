cmake_minimum_required(VERSION 3.12)
project(chapter10 C)

set(CMAKE_C_STANDARD 99)

add_executable(chapter10 main.c main.h sort.h sort.c)