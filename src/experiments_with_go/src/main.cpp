//
// Created by valery on 11/4/19.
//

#include <iostream>
#include "../include/main.hpp"
#include "../include/awesome.h"

int main() {
    GoInt a = 12;
    GoInt b = 99;

    std::cout << "invoking..." << std::endl;

    auto c = Add(a, b);

    std::cout << "result: " << c << std::endl;
}