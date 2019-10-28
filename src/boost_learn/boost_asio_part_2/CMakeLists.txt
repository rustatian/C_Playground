project(boost_learn)
set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_MULTITHREADED ON)

add_executable(boost_asio_part2 src/main.cpp)

target_link_libraries(boost_asio_part2 LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
