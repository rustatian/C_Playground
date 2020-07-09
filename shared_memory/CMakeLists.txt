cmake_minimum_required(VERSION 3.16)

project(shared_memory)

set(CMAKE_EXE_LINKER_FLAGS "-lrt -lpthread" CACHE INTERNAL "" FORCE)
add_executable(writer src/writer.c include/main.h)
add_executable(reader src/reader.c include/main.h)