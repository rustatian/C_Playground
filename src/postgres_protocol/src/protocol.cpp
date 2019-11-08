//
// Created by valery on 07/11/2019.
//

#include <iostream>
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

}

void Connection::write(char c) {
    message_.push_back(c);
}

void Connection::send_startup_message() {

}

