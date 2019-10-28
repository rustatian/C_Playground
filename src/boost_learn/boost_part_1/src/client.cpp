//
// Created by valery on 26/10/2019.
//

#include <string>
#include <boost/system/error_code.hpp>
#include "../include/client.hpp"
#include <iostream>

#ifdef __APPLE__

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/address.hpp>

#endif
#ifdef __LINUX__
#include <asio/ip/tcp.hpp>
#include <asio/ip/address.hpp>
#endif

// clien endpoint
int main() {
    std::string raw_ip_address = "127.0.0.1";

    unsigned short port_num = 3333;

    //used to store info about error
    boost::system::error_code ec;

    boost::asio::ip::address ip_address =
            boost::asio::ip::address::from_string(raw_ip_address, ec);

    if (ec.value() != 0) {
        std::cout << "failed to parse ip address" <<
                  "Error code is: " << ec.value() << "Message: " <<
                  ec.message() << std::endl;
    }
    //step 3
    boost::asio::ip::tcp::endpoint ep(ip_address, port_num);

    // now endpoint are ready
    return 0;
}