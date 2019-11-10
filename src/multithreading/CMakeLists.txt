project(multithreading)
set(CMAKE_CXX_STANDARD 20)
find_package(Threads)

add_executable(hw
        src/lifetime_mistake.cpp
        src/background_task.cpp
        src/hello_multithreading_world.cpp
        include/hello_multithreading_world.hpp
        src/waiting_for_finish.cpp
        include/waiting_for_finish.hpp
        src/RAII.cpp
        src/detached_threads.cpp
        )

target_link_libraries(hw ${CMAKE_THREAD_LIBS_INIT})