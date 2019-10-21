//
// Created by valery on 20/10/2019.
//

#ifndef PLAYGROUND_PRESERVING_THE_VALID_STATE_HPP
#define PLAYGROUND_PRESERVING_THE_VALID_STATE_HPP

#include <vector>

struct Leaf {

};
struct Branch {

};

class OakTree {
public:
    auto& operator=(const OakTree &other) {
        // if we've got an error here
        // during the copying of branches
        // we've got an updated leafs and old branches
        leafs_ = other.leafs_;
        branches_ = other.branches_;
        return *this;
    }

    std::vector<Leaf> leafs_;
    std::vector<Branch> branches_;
};
auto save_to_disk(const std::vector<OakTree> &trees) {
    // data manipulations
}

class OakTreeCorrect {
public:
    auto& operator=(const OakTree& other) {
        auto leafs = other.leafs_;
        auto branches = other.branches_;

        std::swap(leafs_, leafs);
        std::swap(branches_, branches);
        return *this;
    }

    std::vector<Leaf> leafs_;
    std::vector<Branch> branches_;
};

#endif //PLAYGROUND_PRESERVING_THE_VALID_STATE_HPP
