cmake_minimum_required(VERSION 3.12)
project(chapter6 C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-mcmodel=medium)

add_executable(chapter6 main.c chapter6.c chapter6.h main.h string/unit2_1.h string/unit2_1.c
        list/list.h list/list.c)