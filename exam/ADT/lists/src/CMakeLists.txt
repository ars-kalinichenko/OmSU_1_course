find_package(Threads)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ../../../sorts/src/main.cpp ../../../answers/src/1.cpp ../include/l1_list.h l1_list.cpp)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})