//
// Created by valery on 11/3/19.
//

#include <string_view>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/basic_streambuf.hpp>
#include <boost/asio/read_until.hpp>
#include "../include/client.hpp"
#include <iostream>

class SyncTCPClient {
public:
    SyncTCPClient(const std::string &raw_ip_address, unsigned short port_num) :
            ep_(boost::asio::ip::address::from_string(raw_ip_address), port_num),
            sock_(ioc_) {

        sock_.open(ep_.protocol());
    }

    void connect() {
        sock_.connect(ep_);
    }

    void close() {
        sock_.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
        sock_.close();
    }

    std::string emulateLongComputationOp(unsigned int duration_sec) {
        std::string request = "EMULATE_LONG_COMP_OP" + std::to_string(duration_sec) + "\n";

    }

private:
    void sendRequest(const std::string &request) {
        boost::asio::write(sock_, boost::asio::buffer(request));
    }

    std::string receiveResponse() {
        boost::asio::basic_streambuf buf;
        boost::asio::read_until(sock_, buf, "\n");

        std::istream input(&buf);

        std::string response;
        std::getline(input, response);
        return response;
    }

private:
    boost::asio::io_context ioc_;
    boost::asio::ip::tcp::endpoint ep_;
    boost::asio::ip::tcp::socket sock_;
};

size_t sync_client_run() {
    const std::string raw_ip_address = "127.0.0.1";
    const unsigned short port_num = 3333;

    try {
        SyncTCPClient client(raw_ip_address, port_num);

        // Sync connect.
        client.connect();

        std::cout << "Sending request to the server... "
                  << std::endl;

        std::string response =
                client.emulateLongComputationOp(10);

        std::cout << "Response received: " << response
                  << std::endl;

        // Close the connection and free resources.
        client.close();
    }
    catch (boost::system::system_error &e) {
        std::cout << "Error occured! Error code = " << e.code()
                  << ". Message: " << e.what();

        return e.code().value();
    }

    return 0;
}

int main() {


}