project(grpc_client)

set(CMAKE_CXX_STANDARD 20)
find_package(Protobuf REQUIRED)
#include_directories(${Protobuf_INCLUDE_DIRS})
#link_directories(/usr/local/lib)

#set(protobuf_MODULE_COMPATIBLE TRUE)
#set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
#set(_GRPC_GRPCPP_UNSECURE grpc::grpc++_unsecure)

#message(STATUS ${_GRPC_GRPCPP_UNSECURE})
#message(STATUS "Using protobuf ${protobuf_VERSION}")

add_executable(grpc_client src/grpc_client.cpp include/grpc_client.hpp
        proto/greeter.grpc.pb.cc
        proto/greeter.grpc.pb.h
        proto/greeter.pb.cc
        proto/greeter.pb.h)

add_executable(grpc_server src/grpc_server.cpp
        proto/greeter.grpc.pb.cc
        proto/greeter.grpc.pb.h
        proto/greeter.pb.cc
        proto/greeter.pb.h)

target_link_libraries(grpc_client
        grpc++_unsecure
        ${Protobuf_LIBRARIES})

target_link_libraries(grpc_server
        grpc++_unsecure
        ${Protobuf_LIBRARIES})

