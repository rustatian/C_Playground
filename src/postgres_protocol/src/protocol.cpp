//
// Created by valery on 07/11/2019.
//

#include <iostream>
#include <boost/asio/write.hpp>
#include <boost/asio/read_until.hpp>
#include "../include/protocol.hpp"

Connection::Connection(const std::string &ip_address, unsigned int port_num) :
        ep_(boost::asio::ip::address::from_string(ip_address), port_num),
        sock_(ioc_) {

    sock_.open(ep_.protocol());
}

void Connection::connect() {
    try {
        sock_.connect(ep_, ec_);
    } catch (...) {
        std::cout << ec_.value() << "Message: " << ec_.message() << std::endl;
    }
}

void Connection::write_data() {

}

void Connection::read_response() {
    boost::asio::streambuf buf;
    boost::asio::read_until(sock_, buf, EOF);

    std::istream input(&buf);

    std::string response;

    std::getline(input, response);

    std::cout << response << std::endl;
}

void Connection::write(char c) {
    message_.push_back(c);
}

void Connection::send_startup_message() {
    Connection::write('f');
    Connection::write('\0');
    std::size_t written = sock_.write_some(boost::asio::buffer(message_), ec_);
    if (ec_.value() != 0) {
        std::cout << "ERROR: " << ec_.value() << "MESSAGE: " << ec_.message() << std::endl;
    }
    std::cout << "Written: " << written << std::endl;
    sock_.shutdown(boost::asio::socket_base::shutdown_send);

//   read_response();

}

