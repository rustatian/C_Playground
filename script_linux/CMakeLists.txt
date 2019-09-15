cmake_minimum_required(VERSION 3.14)
project(script_linux)
add_executable(main.h main.c pty_master_open.c pty_master_open.h)