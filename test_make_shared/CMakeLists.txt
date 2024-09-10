cmake_minimum_required(VERSION 3.30 FATAL_ERROR)
project(tmsh LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(tmsh src/main.cpp)
