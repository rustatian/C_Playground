//
// Created by Valery Piashchynski on 10/19/19.
//

#include <vector>
#include <boost/shared_ptr.hpp>
#include "../include/main.hpp"

int main(int argc, char *argv[]) {
    auto t = std::set<std::string>{};
    t.insert("salt");

    // a would have only pepper
    auto a = Bagel{t};
    t.insert("pepper");

    // b would have salt, pepper
    auto b = Bagel{t};
    t.insert("oregano");


    /// shared pointers
    auto boat0 = Boat{std::make_shared<YamahaEngine>(), 6.7f};
    auto boat1 = boat0;

    boat1.set_length(8.56f);
    boat1.get_engine()->set_oil_amount(3.4f);
    // if we now change value in boat1 the value also has been changed in boat0, because
    // of copy semantics


    /// shared pointers with copy restricted
    auto boat3 = Boat_without_copy{std::make_shared<YamahaEngine>(), 6.7f};
    //auto boat4 = boat3;
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
