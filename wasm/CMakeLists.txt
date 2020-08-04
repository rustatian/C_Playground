cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(wasm)

set(CMAKE_C_COMPILER /home/valery/Cache/emsdk/upstream/emscripten/emcc)
set(CMAKE_CXX_COMPILER /home/valery/Cache/emsdk/upstream/emscripten/emcc)

include_directories(emsdk/upstream/emscripten/system/include)

set(CMAKE_CXX_FLAGS "-O3 -s WASM=1 --shell-file ${CMAKE_SOURCE_DIR}/html_template/shell_minimal.html -s NO_EXIT_RUNTIME=1 -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']"")

add_executable(wasm main.cpp main.h)