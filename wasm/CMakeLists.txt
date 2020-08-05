cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
project(wasm)
include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
find_package(Threads REQUIRED FATAL_ERROR)

#add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/drogon)

#FetchContent_Declare(
#        drogon
#        GIT_REPOSITORY https://github.com/an-tao/drogon
#        GIT_TAG v1.0.0-beta19
#)
#FetchContent_MakeAvailable(drogon)
#
#
#
#if (NOT drogon_POPULATED)
#    FetchContent_Populate(drogon)
#    add_subdirectory(${drogon_SOURCE_DIR} ${drogon_BINARY_DIR})
#endif ()

file(GLOB SOURCES *.cpp *.h)

set(CMAKE_C_COMPILER /home/valery/Cache/emsdk/upstream/emscripten/emcc)
set(CMAKE_CXX_COMPILER /home/valery/Cache/emsdk/upstream/emscripten/emcc)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")

add_executable(wasm main.cpp main.h)
set(CMAKE_EXECUTABLE_SUFFIX ".js")

set_target_properties(wasm PROPERTIES LINK_FLAGS "--shell-file ${CMAKE_SOURCE_DIR}/html_template/shell_minimal.html -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']")