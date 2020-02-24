cmake_minimum_required(VERSION 3.16)
project(php_ffi)

set(CMAKE_CXX_STANDARD 20)

add_executable(php_ffi src/main.cpp include/main.hpp)