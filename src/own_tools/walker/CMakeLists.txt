cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(walker)
include(FetchContent)

set(CMAKE_CXX_STANDARD 17)
find_package(Threads REQUIRED)

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG        v2.12.4
)
FetchContent_MakeAvailable(catch2)

if(NOT catch2_POPULATED)
    FetchContent_Populate(catch2)
    add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
endif()

list(APPEND _sources
        src/main.cpp
        src/Walker.cpp
        include/Walker.hpp)
add_executable(walker ${_sources})
target_link_libraries(walker ${CMAKE_THREAD_LIBS_INIT} Catch2)