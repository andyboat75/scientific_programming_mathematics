cmake_minimum_required(VERSION 3.19)
project(series08 VERSION 1.0.1 DESCRIPTION "Matrix calculator")

set(CMAKE_CXX_STANDARD 14)

add_library(matrix SHARED matrix.cpp matrix.hpp)
add_executable(main main.cpp matrix.cpp matrix.hpp 8.4.cpp)
#add_executable(tictactoe tic_tac_toe.cpp)
#file(GLOB SOURCES
#        header-*.hpp
#        source-*.cpp
#        )
#set(
#        SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
#        SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/matrix.cpp
#
#)
#set(
#        HEADERS ${$CMAKE_CURRENT
#)
#add_executable(series08 ${SOURCES})