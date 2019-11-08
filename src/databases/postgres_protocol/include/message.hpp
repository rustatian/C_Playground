//
// Created by valery on 08/11/2019.
//

#ifndef PLAYGROUND_MESSAGE_HPP
#define PLAYGROUND_MESSAGE_HPP


#include <vector>

class message {
    friend class Connection;
private:
    std::vector<char> message_;
};


#endif //PLAYGROUND_MESSAGE_HPP
