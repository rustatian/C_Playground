project(postgres_protocol)

set(CMAKE_CXX_STANDARD 20)
set(Boost_USE_MULTITHREADED ON)

add_executable(postgres_protocol
        src/main.cpp include/main.hpp
        src/protocol.cpp include/protocol.hpp
        src/message.cpp include/message.hpp)

target_link_libraries(postgres_protocol LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})