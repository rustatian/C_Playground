//
// Created by valery on 26/10/2019.
//

#include <string>
#include <boost/system/error_code.hpp>
#include <asio/ip/address.hpp>
#include "../include/client.hpp"
#include <iostream>
#include <asio/ip/tcp.hpp>

// clien endpoint
int main() {
    std::string raw_ip_address = "127.0.0.1";

    unsigned short port_num = 3333;

    //used to store info about error
    asio::error_code ec;

    asio::ip::address ip_address =
            asio::ip::address::from_string(raw_ip_address, ec);

    if (ec.value() != 0) {
        std::cout << "failed to parse ip address" <<
                  "Error code is: " << ec.value() << "Message: " <<
                  ec.message() << std::endl;
    }
    //step 3
    asio::ip::tcp::endpoint ep(ip_address, port_num);

    // now endpoint are ready
    return 0;
}