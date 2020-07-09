//
// Created by valery on 11/23/19.
//

#include <grpcpp/server_builder.h>
#include "../proto/greeter.grpc.pb.h"

class GreeterServiceImpl final : public cpp_grpc::Greeter::Service {
    grpc::Status SayHello(grpc::ServerContext *context, const cpp_grpc::HelloRequest *request,
                          cpp_grpc::HelloReply *reply) override {
        std::string prefix("Hello");
        reply->set_message(prefix + request->name());
        return grpc::Status::OK;
    }
};


int main(int, char *[]) {
    std::string address("0.0.0.0:50001");

    GreeterServiceImpl service;

    grpc::ServerBuilder builder;

    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on: " << address << std::endl;

    server->Wait();
}