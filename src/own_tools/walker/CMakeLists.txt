project(walker)
find_package (Threads REQUIRED)

add_executable(walker src/main.cpp src/Walker.cpp include/Walker.hpp )


target_link_libraries(walker ${CMAKE_THREAD_LIBS_INIT})