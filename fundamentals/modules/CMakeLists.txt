set(CMAKE_CXX_STANDARD 20)
list(APPEND CXX_FLAGS "-fmodules")

add_executable(modules user.cpp vector.cpp)
target_compile_options(modules PUBLIC ${CXX_FLAGS})