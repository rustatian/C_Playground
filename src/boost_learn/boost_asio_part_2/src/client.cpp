//
// Created by valery on 29/10/2019.
//

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include "../include/client.hpp"

int main() {
    std::string ip_address = "127.0.0.1";
    unsigned short port_num = 3333;


    boost::asio::io_context ioc;
    boost::asio::ip::tcp::endpoint ep(
            boost::asio::ip::address::from_string(ip_address),
            port_num);


    boost::asio::ip::tcp::socket socket(ioc, ep.protocol());
    try {
        socket.connect(ep);
    } catch (boost::system::error_code &e) {
        std::cout << "error message is: " << e.message() << "error code is: " << e.value();
    }

    std::string buf = "some data";

    std::size_t total_bytes_written = 0;

    while (total_bytes_written != buf.length()) {
        total_bytes_written += socket.write_some(
                boost::asio::buffer(buf, buf.length()));
    }
}