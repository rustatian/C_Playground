//
// Created by Valery Piashchynski on 10/19/19.
//

#include <vector>
#include <boost/shared_ptr.hpp>
#include "../include/main.hpp"

int main(int argc, char *argv[]) {
    auto t = std::set<std::string>{};
    t.insert("salt");

    std::shared_ptr;
    auto a = Bagel{t};

    t.insert("pepper");

    auto b = Bagel{t};
    t.insert("oregano");
}

auto nonmutating_func(const std::vector<Team> &teams) {
    auto tot_age = int{0};

    for (const auto &team: teams) {
        tot_age += team.leader().age();
    }

    for (auto &team: teams) {
        // won't compile, because teams is const
        // team.leader().set_age(20);
    }
}

auto mutating_func(std::vector<Team> &teams) {
    auto tot_age = int{0};

    for (auto &team: teams) {
        team.leader().set_age(10);
    }
}
