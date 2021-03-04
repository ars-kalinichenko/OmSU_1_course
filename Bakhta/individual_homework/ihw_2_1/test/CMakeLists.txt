cmake_minimum_required(VERSION 3.17)
project(tester)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") # CMAKE_CURRENT_LIST_DIR is the directory holding the CMakeLists.txt we are currently using

add_executable(tester main.cpp tester.h tester.cpp)

include(FindPkgConfig)
find_package(SeqRes REQUIRED)
include_directories(${SEQRES_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SEQRES_LIBRARY})
