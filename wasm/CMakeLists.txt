cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(wasm)

file(GLOB SOURCES *.cpp *.h)

set(CMAKE_C_COMPILER /home/valery/Cache/emsdk/upstream/emscripten/emcc)
set(CMAKE_CXX_COMPILER /home/valery/Cache/emsdk/upstream/emscripten/emcc)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")

add_executable(wasm main.cpp main.h)
set(CMAKE_EXECUTABLE_SUFFIX ".js")

set_target_properties(wasm PROPERTIES LINK_FLAGS "--shell-file ${CMAKE_SOURCE_DIR}/html_template/shell_minimal.html -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']")