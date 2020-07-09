project(kernel_experiments)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
add_executable(ke src/kernel_experiments.cpp include/kernel_experiments.hpp)