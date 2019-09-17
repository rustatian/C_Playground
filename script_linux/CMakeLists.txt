cmake_minimum_required(VERSION 3.14)
project(script_linux)
add_executable(pty_master_open.c pty_master_open.h ptyFork.c ptyFork.h errors.c errors.h recorder.c recorder.h)