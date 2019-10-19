//
// Created by Valery Piashchynski on 10/19/19.
//

#include "../include/main.hpp"

int main(int argc, char *argv[]) {
    auto t = std::set<std::string>{};
    t.insert("salt");

    auto a = Bagel{t};

    t.insert("pepper");

    auto b = Bagel{t};
    t.insert("oregano");
}

