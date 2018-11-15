cmake_minimum_required(VERSION 3.6)
project(chapter3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c main.h unit1_2.h unit1_2.c main.c unit1_3.h unit1_3.c unit1_4.h unit1_4.c unit2_2.h unit2_2.c unit2_3.c unit2_3.h linkList.h unit2_4.c unit2_4.h)
add_executable(chapter3 ${SOURCE_FILES})