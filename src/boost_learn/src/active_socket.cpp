//
// Created by valery on 26/10/2019.
//

#include <boost/asio.hpp>
#include <iostream>


int connect_to_socket() {
    std::string ip_address = "127.0.0.1";
    unsigned short port_num = 3333;

    try {
        boost::asio::io_service ios;
        boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(ip_address), port_num);

        boost::asio::ip::tcp::socket sock(ios, ep.protocol());

        sock.connect(ep);
    } catch (boost::system::error_code &e) {
        std::cout << "Error occured! Error code = " << e.value()
                  << ". Message: " << e.message();

        return e.value();
    }


}

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

    connect_to_socket();

    return 0;
}