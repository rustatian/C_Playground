//
// Created by valery on 29/10/2019.
//

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <boost/asio/read.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/read_until.hpp>
#include "../include/server.hpp"

int main() {
    std::string ip_address = "127.0.0.1";
    unsigned short port_num = 3333;

    boost::asio::io_context ioc;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(ip_address), port_num);


    boost::system::error_code ec;
    boost::asio::ip::tcp::acceptor acceptor(ioc, ep.protocol());

    acceptor.bind(ep);
    acceptor.listen(30);
    boost::asio::ip::tcp::socket sock(ioc, ep.protocol());

    try {
        boost::asio::ip::tcp::socket accepted_socket = acceptor.accept();
        boost::asio::streambuf response;

        size_t s = boost::asio::read_until(accepted_socket, response, EOF);
        std::cout << "received size is: " << s << std::endl;
        std::cout << "error message: " << ec.message() << std::endl;
//        std::cout << "data is: " << static_cast<std::string*>(buf.data()) << std::endl;

    } catch (boost::system::error_code &e) {
        std::cout << e.value() << "message: " << e.message();
    }

}