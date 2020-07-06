cmake_minimum_required(VERSION 3.14)
set(CMAKE_C_STANDARD 20)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_SHARED_LINKER_FLAGS -lutil)
project(recorder)

add_executable(ttyrec.h ttyrec.c io.h io.c)