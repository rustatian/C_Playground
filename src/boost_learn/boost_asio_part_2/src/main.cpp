//
// Created by valery on 28/10/2019.
//
#include <boost/asio/buffer.hpp>
#include <iostream>

int fixed_len_io_buffers() {
//    boost::asio::mutable_buffer;
//    boost::asio::const_buffer;
}

const int& max(const int& a, const int& b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int x = 3, y = 5;
    int a = max(x, y) + max(3, 4);
    std::cout << a;
}

