cmake_minimum_required(VERSION 3.6)
project(chapter2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES unit3.c main.h linkList.h list.h unit2.c)
add_executable(chapter2 ${SOURCE_FILES})