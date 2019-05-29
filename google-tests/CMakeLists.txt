cmake_minimum_required(VERSION 3.13)
project(google-test)

enable_testing()

add_executable(google-test main.c main.h main_unittest.c)