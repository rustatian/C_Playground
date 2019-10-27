//
// Created by Valery Piashchynski on 10/27/19.
//

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>


int dns() {
    std::string host = "samplehost.com";
    std::string port_num = "3333";

    boost::asio::io_service ios;

    boost::asio::ip::tcp::resolver::query resolver_query(
            host,
            port_num,
            boost::asio::ip::tcp::resolver::query::numeric_service);
    boost::system::error_code ec;
    boost::asio::ip::tcp::resolver resolver(ios);

    boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(resolver_query, ec);
    // Handling errors if any.
    if (ec.value() != 0) {
        // Failed to resolve the DNS name. Breaking execution.
        std::cout << "Failed to resolve a DNS name."
                  << "Error code = " << ec.value()
                  << ". Message = " << ec.message();

        return ec.value();
    }

    return 0;
}

int main() {
    boost::asio::io_service ios;
    boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4();
    boost::system::error_code ec;

    boost::asio::ip::tcp::acceptor acceptor(ios);
    acceptor.open(protocol, ec);
    if (ec.value() != 0) {
        //ec.message()
    }

    dns();

}