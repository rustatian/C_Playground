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


class Engine {
public:
    auto set_oil_amount(float v) {
        oil_ = v;
    }
    [[nodiscard]] float get_oil_amount() const {
        return oil_;
    }

private:
    float oil_ {};
};

class YamahaEngine : public Engine {

};

// copy semantics
class Boat {
public:
    Boat(std::shared_ptr<Engine> e, float l) : engine_{e}, length_{l} {};
    auto set_length(float l) {
        length_ = l;
    }
    auto &get_engine() {
        return engine_;
    }
private:
    std::shared_ptr<Engine> engine_;
    float length_{};
};

class Boat_without_copy {
private:
    Boat_without_copy(const Boat_without_copy& b) = delete; //noncopyable
    //auto operator = (const Boat_without_copy&) -> Boat_without_copy& = delete; //trailing return
    Boat_without_copy& operator = (const Boat_without_copy&) = delete; //noncopyable
public:
    Boat_without_copy(std::shared_ptr<Engine> e, float l) : engine_{e}, length_{l} {};
    auto set_length(float l) {
        length_ = l;
    }
    auto &get_engine() {
        return engine_;
    }
private:
    std::shared_ptr<Engine> engine_;
    float length_{};
};


#endif //PLAYGROUND_MAIN_HPP
