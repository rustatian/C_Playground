cmake_minimum_required(VERSION 3.14)

set (CMAKE_CXX_STANDARD 11)

IF(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
ENDIF()

project(opencv_tests)

# Requires OpenCV
FIND_PACKAGE(OpenCV 4.1.1 REQUIRED )
MESSAGE("OpenCV version : ${OpenCV_VERSION}")

add_executable(opencv_tests main.cpp)
TARGET_LINK_LIBRARIES(opencv_tests ${OpenCV_LIBS} ${CONAN_LIBS} )

add_executable(video video.cpp)
TARGET_LINK_LIBRARIES(video ${OpenCV_LIBS} ${CONAN_LIBS} )