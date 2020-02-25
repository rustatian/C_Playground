cmake_minimum_required(VERSION 3.16)
project(php_ffi)

set(CMAKE_CXX_STANDARD 20)

find_package(ImageMagick COMPONENTS Magick++)
find_program(MAGICK_CONFIG "Magick++-config")

# Ask about CXX and lib flags/locations
execute_process(COMMAND "${MAGICK_CONFIG}" "--cxxflags" OUTPUT_VARIABLE MAGICK_CXX_FLAGS)
execute_process(COMMAND "${MAGICK_CONFIG}" "--libs" OUTPUT_VARIABLE MAGICK_LD_FLAGS)

# Remove trailing whitespace (CMAKE warns about this)
string(STRIP "${MAGICK_CXX_FLAGS}" MAGICK_CXX_FLAGS)
string(STRIP "${MAGICK_LD_FLAGS}" MAGICK_LD_FLAGS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a ${MAGICK_CXX_FLAGS} ${MAGICK_LD_FLAGS}")
#set(SOURCE_FILES src/main.cpp)

add_executable(php_ffi src/main.cpp include/main.hpp)

add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16 )
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0 )
include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(php_ffi ${ImageMagick_LIBRARIES})