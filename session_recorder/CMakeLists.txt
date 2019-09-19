cmake_minimum_required(VERSION 3.14)
set(CMAKE_C_STANDARD 11)
set(CMAKE_SHARED_LINKER_FLAGS -lutil)
project(recorder)

add_executable(../linux_sources/script.c ../linux_sources/script.h)