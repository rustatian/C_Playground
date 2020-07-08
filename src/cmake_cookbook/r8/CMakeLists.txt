cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(r8 LANGUAGES CXX)

list(APPEND _sources geometry_circle.cpp geometry_circle.h)

add_executable(r8 compute-areas.cpp ${_sources})