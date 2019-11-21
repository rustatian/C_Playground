//
// Created by valery on 11/21/19.
//

#include <iostream>
#include <filesystem>
#include "../include/Walker.hpp"

int main(int argc, char *argv[]) {
    // usage:
    // firs arg is dir with repos
    // second - pull or push
    // third - push or pull
    // both or just one
    if (argc < 2) {
        std::cerr << "Not enough args";
        return 1;
    }

    if (argc > 2) {
        throw std::runtime_error("wrong number of parameters");
    }

    Walker w{};

    for (const std::filesystem::directory_entry &entry: std::filesystem::directory_iterator(argv[1])) {
        if (entry.is_directory()) {
            w.add_repo(entry.path().string());
        }
    }

    w.pull_repos();
    w.push_origin();
}