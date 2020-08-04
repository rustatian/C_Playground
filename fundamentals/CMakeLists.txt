cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(fundamentals LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 CONFIG REQUIRED)

add_subdirectory(classes)
add_subdirectory(deducing_types)
#add_subdirectory(modules)
