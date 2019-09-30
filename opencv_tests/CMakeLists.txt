cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
SET(OpenCV_DIR /usr/local/Cellar/opencv/4.1.1_2/lib/cmake/opencv4)
project(opencv_tests)

add_executable(main.h main.cpp)