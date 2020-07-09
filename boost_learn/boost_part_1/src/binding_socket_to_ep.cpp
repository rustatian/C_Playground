//
// Created by valery on 28/10/2019.
//


#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

int main() {
    std::string host = "127.0.0.1";
    unsigned short port = 3333;

    boost::asio::io_service ios;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::any(), port);

    boost::asio::ip::tcp::acceptor acceptor(ios, ep.protocol());
    acceptor.bind(ep);
}
