//
// Created by valery on 26/10/2019.
//

#include <asio/ip/address.hpp>
#include <asio/ip/tcp.hpp>
#include "../include/server.hpp"

int main() {
    unsigned short port_num = 3333;
    asio::ip::address ip_address = asio::ip::address_v4::any();

    asio::ip::tcp::endpoint ep(ip_address, port_num);
}