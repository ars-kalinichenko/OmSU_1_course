cmake_minimum_required(VERSION 3.17)
project(OmSU_2020 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14) # стандарт с++ 2014

# set your path to subproject(seminars, labs, ihw)
set(MAIN_DIR ${PROJECT_SOURCE_DIR}/exam/ADT/lists)

set(PROJECT_HEADERS_DIR ${MAIN_DIR}/include)
set(PROJECT_SOURCES_DIR ${MAIN_DIR}/src)

#todo: global to local
file(GLOB_RECURSE HEADERS ${MAIN_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${MAIN_DIR}/*.cpp)


include_directories(${MAIN_DIR})
add_subdirectory(${MAIN_DIR}/src)


