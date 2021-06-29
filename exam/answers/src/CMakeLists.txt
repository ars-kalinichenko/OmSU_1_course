find_package(Threads)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} 2.cpp 3.cpp ../../ADT/lists/src/deque.cpp ../../ADT/lists/include/deque.h ../../ADT/arrays/include/deque.h ../../ADT/arrays/src/deque.cpp)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})