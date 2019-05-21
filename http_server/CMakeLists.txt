cmake_minimum_required(VERSION 3.13)
project(http_server)

add_executable(http_server main.c main.h ../memory_alloc/main.c)