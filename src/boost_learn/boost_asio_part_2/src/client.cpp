//
// Created by valery on 29/10/2019.
//

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include "../include/client.hpp"

void sync_write() {
    std::string ip_address = "127.0.0.1";
    unsigned short port_num = 3333;


    boost::asio::io_context ioc;
    boost::asio::ip::tcp::endpoint ep(
            boost::asio::ip::address::from_string(ip_address),
            port_num);


    boost::asio::ip::tcp::socket socket(ioc, ep.protocol());
    try {
        socket.connect(ep);
    } catch (boost::system::error_code &e) {
        std::cout << "error message is: " << e.message() << "error code is: " << e.value();
    }

    std::string buf = "soooooooome vveeryyyyy long datatatatatatat";

    std::size_t total_bytes_written = 0;

    while (total_bytes_written != buf.length()) {
        total_bytes_written += socket.write_some(
                boost::asio::buffer(buf, buf.length()));
    }
}

struct SendData {
    boost::asio::ip::tcp::socket *socket;
    char buf[1000];
    std::size_t total_bytes_written;
};

void async_write() {
    using namespace boost;

    asio::io_context ioc;
}

void async_write_handler(const boost::system::error_code &ec, std::size_t bytes_transferred) {

}

template<int N, typename T>
class array_t {
    T data[N];
public:
    [[nodiscard]] const T *begin() const { return data; }

    [[nodiscard]] const T *end() const { return data + N; }

    [[nodiscard]]int size() const { return N; }

    T &operator[](int idx) {
        if (idx < 0 || idx >= N) {
            throw std::range_error("OUT OF RANGE");
        }
        return data[idx];
    }
};

int main() {
    auto t = array_t<4, int>();

    std::string ip_address = "127.0.0.1";
    unsigned short port_number = 3333;

    boost::asio::io_context ioc;

    boost::asio::ip::tcp::endpoint ep();
}

