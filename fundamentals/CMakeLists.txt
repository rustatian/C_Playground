cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

#set(CMAKE_C_COMPILER "clang")
#set(CMAKE_CXX_COMPILER "clang++")

project(fundamentals LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(classes)
add_subdirectory(deducing_types)
#add_subdirectory(modules)
