cmake_minimum_required(VERSION 3.19)
project(pythagorean_thriple)

set(CMAKE_CXX_STANDARD 14)

add_executable(pythagorean_thriple main.cpp PyTriple.cpp PyTriple.h gcd.h)