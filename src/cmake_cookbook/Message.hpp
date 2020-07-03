#pragma once
#ifndef RECIPE_01_MESSAGE_HPP

#include <iosfwd>
#include <string>

#define RECIPE_01_MESSAGE_HPP

class Message {
public:
    Message(const std::string &m) : message_(m) {

    }

    friend std::ostream &operator<<(std::ostream &os, Message &obj) {
        return obj.printObject(os);
    }

private:
    std::string message_;
    std::ostream &printObject(std::ostream &os);
};


#endif //RECIPE_01_MESSAGE_HPP
