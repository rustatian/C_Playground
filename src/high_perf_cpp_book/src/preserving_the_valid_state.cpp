//
// Created by valery on 20/10/2019.
//

#include "../include/preserving_the_valid_state.hpp"

int main() {
    auto tree0 = OakTree{std::vector<Leaf>{1000},
                         std::vector<Branch>{100}};

    auto tree1 = OakTree{std::vector<Leaf>{50},
                         std::vector<Branch>{5}};
    try {
        tree0 = tree1;
    }
    catch (const std::exception& e) {
        save_to_disk({tree0, tree1});
    }

}

