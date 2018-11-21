cmake_minimum_required(VERSION 3.12)
project(chapter7 C)

set(CMAKE_C_STANDARD 99)

add_executable(chapter7 main.c unit1.h main.h unit1.c btree.h unit4.c unit4.h unit5.c unit5.h unit6.c unit6.h)