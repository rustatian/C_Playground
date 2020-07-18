cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(modern_assembly)

set(CMAKE_ASM_OBJECT_FORMAT elf64)
enable_language(ASM_NASM)

add_library(nn OBJECT Ch02_01.asm)

set(CMAKE_CXX_STANDARD 20)

add_executable(modern_assembly main.cpp)
target_link_libraries(modern_assembly nn)
