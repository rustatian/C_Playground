cmake_minimum_required(VERSION 3.13)
project(http_server)

add_executable(http_server
        ${BOOST_BEAST_FILES}
        ${COMMON_FILES}
        fast_server.cpp fast_server.hpp)

set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME ON)

include_directories (/usr/lib)

target_link_libraries(http_server
        asio
        beast)