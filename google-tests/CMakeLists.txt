cmake_minimum_required(VERSION 3.13)
project(google-test)

include_directories(/usr/local/Cellar/catch2/2.8.0/include/catch2)
enable_testing()


add_executable(google-test main.c main.h test_main.c test_pb.c)