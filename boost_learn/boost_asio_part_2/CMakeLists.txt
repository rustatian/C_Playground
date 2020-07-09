project(boost_learn)
set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_MULTITHREADED ON)

add_executable(boost_asio_part2 src/main.cpp src/server.cpp include/server.hpp)
add_executable(part2_client src/client.cpp include/client.hpp)
add_executable(part2_server src/server.cpp include/server.hpp)

target_link_libraries(boost_asio_part2 LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
target_link_libraries(part2_client LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
target_link_libraries(part2_server LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
