cmake_minimum_required(VERSION 3.14)
project(script_linux)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
#set_property(TARGET script_linux PROPERTY C_STANDARD 11)
add_executable(ptyFork.h pty_master_open.h errors.h tty_raw.h
        pty_master_open.c ptyFork.c errors.c tty_raw.c recorder.h recorder.c replay.c replay.h)

#add_executable(replay.h)