project(grpc_client)

set(CMAKE_CXX_STANDARD 20)
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})

add_executable(grpc_client src/grpc.cpp include/grpc.hpp
        proto/greeter.grpc.pb.cc
        proto/greeter.grpc.pb.h
        proto/greeter.pb.cc
        proto/greeter.pb.h)
target_link_libraries(grpc_client grpc ${Protobuf_LIBRARIES} ${_GRPC_GRPCPP_UNSECURE} ${_PROTOBUF_LIBPROTOBUF})


