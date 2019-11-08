//
// Created by valery on 07/11/2019.
//

#ifndef PLAYGROUND_PROTOCOL_HPP
#define PLAYGROUND_PROTOCOL_HPP

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>

// For historical reasons,
// the very first message sent by the client (the startup message)
// has no initial message-type byte.
// boost::serialization
struct Send {
    // message type according to the protocol 1 byte
    char message_type;
    // message len 4 bytes
    char message_len[4];

    // rest of the body
    char body[];

};


class Connection {
public:
    Connection(const std::string &ip_address, unsigned int port_num);

    void connect() noexcept(false);

    void write_data();

    void read_response();

    // write message char to vector
    void write(char c);

    void send_startup_message();

private:
    mutable std::vector<char> message_;
    boost::asio::streambuf buf_;
    boost::system::error_code ec_;
    boost::asio::io_context ioc_;
    boost::asio::ip::tcp::socket sock_;
    boost::asio::ip::tcp::endpoint ep_;
};

#endif //PLAYGROUND_PROTOCOL_HPP
