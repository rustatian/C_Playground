#include <iostream>

extern "C" int64_t integeraddsub(int64_t, int64_t, int64_t, int64_t);

int main() {
    auto a = integeraddsub(1, 2, 3, 1);
    std::cout << a << std::endl;
}

