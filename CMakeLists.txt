cmake_minimum_required(VERSION 3.30)
project(AoC2024InC)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AoC2024InC
    Inputs/inputday1
    Day1.cpp
    Day1.h)
