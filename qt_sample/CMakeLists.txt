cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(qt_samples LANGUAGES CXX)

include_directories(/opt/Qt/5.15.0/gcc_64/include)
set(CMAKE_PREFIX_PATH /opt/Qt/5.15.0/gcc_64/)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)

add_executable(qt_samples main.cpp fortunethread.cpp fortunethread.h blockingclient.cpp blockingclient.h)
target_link_libraries(qt_samples Qt5::Widgets Qt5::Network)