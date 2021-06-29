find_package(Threads)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} 2.cpp 3.cpp)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})