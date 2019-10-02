CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
set (CMAKE_CXX_STANDARD 17)
PROJECT(debugger)

ADD_EXECUTABLE(debugger main.cpp main.h debugger.cpp debugger.h)