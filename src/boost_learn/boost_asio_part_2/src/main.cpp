//
// Created by valery on 28/10/2019.
//
#include <boost/asio/buffer.hpp>
#include <iostream>
#include <boost/asio/streambuf.hpp>

void extensible_stream_oriented_io_buffers() {
    boost::asio::streambuf buf;
    std::ostream output(&buf);

    output << "Message1\nMessage2";

    std::istream input(&buf);
    std::string message1;

    std::getline(input, message1);

    std::cout << message1;

}


int fixed_len_io_buffers() {
    // PREPARING BUFFER FOR OUTPUT OPERATION
    std::string buf;
    buf = "Hello";

    boost::asio::const_buffer output_buf = boost::asio::buffer(buf);


    // PREPARING BUFFER FOR INPUT OPERATION

    // allocate the buffer
    const size_t BUF_SIZE_BYTES = 20;
    std::unique_ptr<char[]> buf2(new char[BUF_SIZE_BYTES]);

    boost::asio::mutable_buffer input_buf = boost::asio::buffer(
            static_cast<void*>(buf2.get()),
            BUF_SIZE_BYTES);

    // asio input operations can be made here

}


int main() {
    extensible_stream_oriented_io_buffers();
}

