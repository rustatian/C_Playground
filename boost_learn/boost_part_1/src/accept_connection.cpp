//
// Created by valery on 28/10/2019.
//

#include <string>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

int main() {
    std::string ip_address = "127.0.0.1";
    unsigned short port_number = 3333;

    boost::asio::io_context ioc;


    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(ip_address), port_number);
    boost::asio::ip::tcp::acceptor acceptor(ioc, ep.protocol());

    acceptor.bind(ep);
    acceptor.listen();

    boost::asio::ip::tcp::socket sock(ioc, ep.protocol());

    // now connection is accepted and we are ready to get data
    boost::asio::ip::tcp::socket accepted_socket = acceptor.accept();

}