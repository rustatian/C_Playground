project(multithreading)
set(CMAKE_CXX_STANDARD 20)
find_package(Threads)

add_executable(hw
        src/lifetime_mistake.cpp
        src/background_task.cpp
        src/hello_multithreading_world.cpp
        include/hello_multithreading_world.hpp)

target_link_libraries(hw ${CMAKE_THREAD_LIBS_INIT})