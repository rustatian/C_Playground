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

class Person {
public:
    // age is not allowed to mutate Person object because is declared as const
    auto age() const { return age_;}
    // set_age can mutate the Person object
    auto set_age(int age) {age_ = age;}

private:
    int age_{};
};

class Team {
public:
    auto& leader() const { return leader_;}
    auto& leader() { return leader_;}

private:
    Person leader_{};
};
#endif //PLAYGROUND_MAIN_HPP
