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

struct ReadData {
    std::shared_ptr<boost::asio::ip::tcp::socket> sock;
    std::unique_ptr<char[]> buf;
    std::size_t buffer_size;
    std::size_t bytes_read;
};

void sync_server() {
//    std::string ip_address = "0.0.0.0";
    unsigned short port_num = 3333;

    boost::asio::io_context ioc;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::any(), port_num);


    boost::system::error_code ec;
    boost::asio::ip::tcp::acceptor acceptor(ioc, ep.protocol());

    acceptor.bind(ep);
    acceptor.listen(30);

    try {
        boost::asio::ip::tcp::socket accepted_socket = acceptor.accept();
        std::size_t available = accepted_socket.available();

        std::cout << "data available is: " << available << std::endl;

        char buf[available];

        size_t s = accepted_socket.read_some(boost::asio::buffer(buf, available));
        std::cout << "received size is: " << s << std::endl;
        std::cout << "data is: " << std::string(buf, available) << std::endl;

    } catch (boost::system::error_code &e) {
        std::cout << e.value() << "message: " << e.message();
    }
}

void read_handler(const boost::system::error_code &ec, std::size_t bytes_transferred,
                  std::shared_ptr<boost::asio::ip::tcp::socket> s, std::unique_ptr<char[]> data) {

}

void async_server() {

}

int main() {
    sync_server();
}
