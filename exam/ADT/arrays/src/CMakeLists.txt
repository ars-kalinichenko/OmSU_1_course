find_package(Threads)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ../../lists/include/stack.h ../../lists/src/stack.cpp)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})