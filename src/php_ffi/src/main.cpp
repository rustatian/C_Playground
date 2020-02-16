//
// Created by valery on 16/02/2020.
//


#include <cstdint>

extern "C" int32_t fib(int32_t n) {
    if ((n == 1) || (n == 2)) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {
    fib(12);
}



