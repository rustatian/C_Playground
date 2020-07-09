//
// Created by valery on 21/10/2019.
//

#include <mutex>
#include "../include/recource_acquisition.hpp"


// lifetime of objects
auto func(std::mutex &m, int val, bool b) {
    auto guard = std::lock_guard<std::mutex>{m};
    if (b) {
        // here the guard automatically releses the mutex at early exit
        return;
    }
    if (val == 111) {
        // auto release here as well
        throw std::exception{};
    }

    // also auto release here
}

auto mref() -> int & {

}

auto &mrefw() {
    int a = 5;

    return a;
}

auto func(const std::string &a, const std::string &b) {
    const auto &str = a + b;
}

struct Foo {
    // just value
    auto val() const {
        return m_;
    }

    // const reference
    auto &cref() const {
        return m_;
    }

    // mutable reference
    // cannot bind to a temporary
    auto &mref() {
        return m_;
    }

    int m_{};
};

int main() {
    auto foo = Foo{};
    auto &cref = foo.cref();
    auto &mref = foo.mref();
}