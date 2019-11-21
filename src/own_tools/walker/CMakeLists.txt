project(walker)
add_executable(walker src/Walker.cpp include/Walker.hpp)
find_package (Threads REQUIRED)

target_link_libraries(walker ${CMAKE_THREAD_LIBS_INIT})