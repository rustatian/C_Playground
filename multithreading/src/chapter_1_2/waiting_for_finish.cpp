//
// Created by valery on 10/11/2019.
//

#include "../../include/waiting_for_finish.hpp"

#include <thread>

struct func2 {
    int &i;

    explicit func2(int &i_) : i(i_) {}

    void operator()() {
        for (unsigned j = 0; j < 1000000; ++j) {
            //do_smt();
        }
    }
};

void f11() {
    int some_local_state = 0;

    func2 my_func(some_local_state);

    std::thread t(my_func);

    try {
        //do_smt_in_current_thread();
    } catch (...) {
        t.join();
        throw;
    }
    t.join();
}