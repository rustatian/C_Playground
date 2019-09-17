cmake_minimum_required(VERSION 3.14)
project(script_linux)
add_executable(recorder.h ptyFork.h pty_master_open.h errors.h tty_raw.h
        pty_master_open.c ptyFork.c errors.c tty_raw.c recorder.c)