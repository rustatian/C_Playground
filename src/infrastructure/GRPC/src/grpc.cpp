//
// Created by valery on 11/21/19.
//

#include "../include/grpc.hpp"
#include <grpcpp/grpcpp.h>
#include "../proto/greeter.grpc.pb.h"

class GreeterClient {
public:
    GreeterClient(std::shared_ptr<grpc::Channel> channel) : stub_(cpp_grpc::Greeter::NewStub(channel)) {}

    std::string SayHello(const std::string &user) {
        cpp_grpc::HelloRequest request;
        request.set_name(user);

        cpp_grpc::HelloReply reply;

        grpc::ClientContext context;

        grpc::Status status = stub_->SayHello(&context, request, &reply);

        if (status.ok()) {
            return reply.message();
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return "RPC failed";
        }
    }

private:
    std::unique_ptr<cpp_grpc::Greeter::Stub> stub_;
};





int main(int, char*[]) {
    GreeterClient greeter(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));

    std::string user("world");

    std::string reply = greeter.SayHello(user);

    std::cout << "Greeter received: " << reply << std::endl;

    return 0;
}