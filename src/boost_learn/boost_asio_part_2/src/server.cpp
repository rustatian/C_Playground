//
// Created by valery on 29/10/2019.
//

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <iostream>
#include <boost/asio/read.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/read_until.hpp>
#include <thread>
#include "../include/server.hpp"

struct ReadData {
    std::shared_ptr<boost::asio::ip::tcp::socket> sock;
    std::unique_ptr<char[]> buf;
    std::size_t total_bytes_read;
    unsigned int buf_size;
};

void sync_server() {
//    std::string ip_address = "0.0.0.0";
    unsigned short port_num = 3333;

    boost::asio::io_context ioc;
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::any(), port_num);


    boost::system::error_code ec;
    boost::asio::ip::tcp::acceptor acceptor(ioc, ep.protocol());

    acceptor.bind(ep);
    acceptor.listen(30);

    try {
        boost::asio::ip::tcp::socket accepted_socket = acceptor.accept();
        std::size_t available = accepted_socket.available();

        std::cout << "data available is: " << available << std::endl;

        char buf[available];

        size_t s = accepted_socket.read_some(boost::asio::buffer(buf, available));
        std::cout << "received size is: " << s << std::endl;
        std::cout << "data is: " << std::string(buf, available) << std::endl;

    } catch (boost::system::error_code &e) {
        std::cout << e.value() << "message: " << e.message();
    }
}

void read_handler(const boost::system::error_code &ec, std::size_t bytes_transferred,
                  const std::shared_ptr<ReadData> &rd) {
    if (ec.value() != 0) {
        std::cout << "Error code is: " << ec.value() << "Message is: " << ec.message() << std::endl;
        return;
    }

    rd->total_bytes_read += bytes_transferred;

    if (rd->total_bytes_read == rd->buf_size) {
        return;
    }

//    std::function<void(const boost::system::error_code,
//                       std::size_t,
//                       std::shared_ptr<ReadData>)> m_read_handler;

//    auto m_read_handler = [=]() {
//        return read_handler(std::placeholders::_1,std::placeholders::_2,std::placeholders::_3);
//    };


    rd->sock->async_read_some(
            boost::asio::buffer(rd->buf.get(), rd->buf_size),
            std::bind(read_handler, std::placeholders::_1, std::placeholders::_2, rd));
}


void async_server() {
    unsigned short port_num = 3333;

    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::any(), port_num);
    boost::asio::io_context ioc;

    std::shared_ptr<boost::asio::ip::tcp::socket> sock(
            new boost::asio::ip::tcp::socket(ioc, ep.protocol()));

    std::shared_ptr<ReadData> rd(new ReadData);

    try {
//        sock->connect(ep);

        sock->async_connect(ep,
                            [sock](const boost::system::error_code &ec) noexcept {
                                if (ec.value() != 0) {
                                    if (ec == boost::asio::error::operation_aborted) {
                                        std::cout << "Operation cancelled" << std::endl;
                                    } else {
                                        std::cout << "Error code is: " << ec.value() << "Message is: " << ec.message()
                                                  << std::endl;
                                        return;
                                    }
                                }
                            });

        std::thread worker_thread([&ioc]() {
            try {
                // just sample
                ioc.run();
            } catch (boost::system::system_error &e) {
                std::cout << "Error occured!"
                          << " Error code = " << e.code()
                          << ". Message: " << e.what();
            }
        });

        std::this_thread::sleep_for(std::chrono::seconds(10));

        sock->cancel();

        worker_thread.join();
        // allocate a buffer
//        const unsigned int MESSAGE_SIZE = 7;
//        rd->buf.reset(new char[MESSAGE_SIZE]);
//        rd->sock = std::move(sock);
//        rd->total_bytes_read = 0;
//        rd->buf_size = MESSAGE_SIZE;
//
//        rd->sock->async_read_some(
//                boost::asio::buffer(rd->buf.get(), rd->buf_size),
//                std::bind(read_handler, std::placeholders::_1, std::placeholders::_2, rd)
//        );
//
//        ioc.run();

    } catch (boost::system::error_code &ec) {
        std::cout << "Error occured! Error code = " << ec.value()
                  << ". Message: " << ec.message();

    }
}

int main() {
    async_server();
}
