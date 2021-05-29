find_package(Threads)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ../include/stack.h stack.cpp test.cpp ../include/test.h)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(${PROJECT_NAME} ncurses)