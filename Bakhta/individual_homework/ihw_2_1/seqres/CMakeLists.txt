cmake_minimum_required(VERSION 3.17)
project(ihw_4)

set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE SOURCES *.cpp)
add_executable(ihw_4 main.cpp analyzer.cpp analyzer.h)
add_library(ihw_4 STATIC main.cpp analyzer.cpp)