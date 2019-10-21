//
// Created by valery on 21/10/2019.
//

#include <mutex>
#include "../include/recource_acquisition.hpp"

int main() {

}

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

auto val() const -> int {

}