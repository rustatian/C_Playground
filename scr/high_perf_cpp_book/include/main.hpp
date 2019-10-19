//
// Created by Valery Piashchynski on 10/19/19.
//

#ifndef PLAYGROUND_MAIN_HPP
#define PLAYGROUND_MAIN_HPP
#include <set>
#include <string>
#include <iostream>

class Bagel {
public:
    Bagel(const std::set<std::string> &ts) : toppings_(ts){}

private:
    std::set<std::string> toppings_;
};


#endif //PLAYGROUND_MAIN_HPP
