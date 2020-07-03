cmake_minimum_required(VERSION 3.17 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER clang++)
project(cmake LANGUAGES CXX)

option(USE_LIBRARY "Compile sources into a library" OFF)
message(STATUS "Compile sources into a library? ${USE_LIBRAY}")
set(BUILD_SHARED_LIBS OFF)
list(APPEND _sources Message.cpp Message.hpp)

message(STATUS "C flags, Debug configuration: ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "C flags, Release configuration: ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "C flags, Release configuration with Debug info: ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
message(STATUS "C flags, minimal Release configuration: ${CMAKE_C_FLAGS_MINSIZEREL}")

message(STATUS "C++ flags, Debug configuration: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "C++ flags, Release configuration: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "C++ flags, Release configuration with Debug info: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message(STATUS "C++ flags, minimal Release configuration: ${CMAKE_CXX_FLAGS_MINSIZEREL}")

if (USE_LIBRARY)
    add_library(message STATIC ${_sources})
    add_executable(hello-world hello-world.cpp)
    target_link_libraries(hello-world message)
else()
    add_executable(hello-world hello-world.cpp ${_sources})
endif()

#include(CMakeDependentOption)
#
#cmake_dependent_option(MAKE_STATIC_LIBRARY "Compile sources into a static library" OFF
#        "USE_LIBRARY" ON)
#cmake_dependent_option(MAKE_SHARED_LIBRARY "Compile sources into a shared library" ON
#        "USE_LIBRARY" ON)

#add_library(message-objs
#        OBJECT
#        Message.hpp
#        Message.cpp
#        )
#
#add_library(message-shared SHARED $<TARGET_OBJECTS:message-objs>)
#add_library(message-static STATIC $<TARGET_OBJECTS:message-objs>)
#
#add_executable(hello-world hello-world.cpp)
#target_link_libraries(hello-world message-static)