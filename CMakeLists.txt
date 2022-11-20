cmake_minimum_required(VERSION 3.23)
project(C_Ex1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C_Ex1
        advancedClassificationLoop.c
        advancedClassificationRecursion.c
        basicClassification.c
        main.c
        NumClass.h)
