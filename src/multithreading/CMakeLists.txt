project(multithreading)
set(CMAKE_CXX_STANDARD 20)
find_package(Threads)

add_executable(hw
        src/chapter_1_2/lifetime_mistake.cpp
        src/chapter_1_2/background_task.cpp
        src/chapter_1_2/hello_multithreading_world.cpp
        include/hello_multithreading_world.hpp
        src/chapter_1_2/waiting_for_finish.cpp
        include/waiting_for_finish.hpp
        src/chapter_1_2/RAII.cpp
        src/chapter_1_2/detached_threads.cpp
        src/chapter_1_2/joining_threads.cpp include/joining_threads.hpp src/chapter_1_2/parallel_accumulate.cpp)

target_link_libraries(hw ${CMAKE_THREAD_LIBS_INIT})