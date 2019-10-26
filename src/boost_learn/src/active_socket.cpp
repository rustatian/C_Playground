//
// Created by valery on 26/10/2019.
//

#include <boost/asio.hpp>
#include <iostream>

int main() {
    boost::asio::io_service ios;
    boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4();

    boost::asio::ip::tcp::socket sock(ios);
    boost::system::error_code ec;

    sock.open(protocol, ec);
    if (ec.value() != 0) {
        std::cout << "failed to parse ip address" <<
                  "Error code is: " << ec.value() << "Message: " <<
                  ec.message() << std::endl;
    }

    return 0;
}