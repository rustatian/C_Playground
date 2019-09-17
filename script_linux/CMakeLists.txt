cmake_minimum_required(VERSION 3.14)
project(script_linux)
#set_property(TARGET script_linux PROPERTY C_STANDARD 11)
set(CMAKE_C_FLAGS "-std=c11")
add_executable(recorder.h ptyFork.h pty_master_open.h errors.h tty_raw.h
        pty_master_open.c ptyFork.c errors.c tty_raw.c recorder.c)