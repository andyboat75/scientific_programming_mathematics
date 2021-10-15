cmake_minimum_required(VERSION 3.19)
project(lec8)

set(CMAKE_CXX_STANDARD 14)

add_library(matrix SHARED matrix.cpp matrix.h)
add_executable(main main.cpp)