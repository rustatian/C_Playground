project(boost_asio_part_3)

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_MULTITHREADED ON)

add_executable(part3_client src/client.cpp include/client.hpp)
add_executable(part3_server src/server.cpp include/server.hpp)


target_link_libraries(part3_client LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
target_link_libraries(part3_server LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})