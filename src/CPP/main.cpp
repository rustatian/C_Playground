//
// Created by valery on 7/12/19.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "string.h"
#include "main.h"


int main() {
    std::cout << "Please, enter you name\n";
    std::string first_name;

    std::cin >> first_name;

    std::cout << "Hello " + first_name + "!";
}