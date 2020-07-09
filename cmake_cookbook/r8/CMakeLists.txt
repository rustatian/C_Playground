cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(r8 LANGUAGES CXX)

add_library(geometry STATIC
        geometry_circle.cpp
        geometry_circle.h
        geometry_polygon.cpp
        geometry_polygon.h
        geometry_rhombus.cpp
        geometry_rhombus.h
        geometry_square.cpp
        geometry_square.h
        )

set(COMPILER_FLAGS)
set(COMPILER_FLAGS_DEBUG)
set(COMPILER_FLAGS_RELEASE)

if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
    list(APPEND CXX_FLAGS "-fno-rtti" "-fno-exceptions" "-std=c++2a")
    list(APPEND CXX_FLAGS_DEBUG "-Wsuggest-final-types" "-Wsuggest-final-methods" "-Wsuggest-override" "-std=c++2a")
    list(APPEND CXX_FLAGS_RELEASE "-O3" "-Wno-unused" "-std=c++2a")
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES Clang)
    list(APPEND CXX_FLAGS "-fno-rtti" "-fno-exceptions" "-Qunused-arguments" "-fcolor-diagnostics" "-std=c++2a")
    list(APPEND CXX_FLAGS_DEBUG "-Wdocumentation" "-std=c++2a")
    list(APPEND CXX_FLAGS_RELEASE "-O3" "-Wno-unused" "-std=c++2a")
endif ()

add_executable(compute-areas compute-areas.cpp)
target_compile_options(compute-areas
        PRIVATE
        ${CXX_FLAGS}
        "$<$<CONFIG:Debug>:${CXX_FLAGS_DEBUG}>"
        "$<$<CONFIG:Release>:${CXX_FLAGS_RELEASE}>"
        )
target_link_libraries(compute-areas geometry)