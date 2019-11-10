//
// Created by Valery Piashchynski on 11/10/19.
//

#include <thread>

struct func {
    int &i;

    explicit func(int &i_) : i(i_) {}

    void operator()() {
        for (unsigned j = 0; j < 1000000; ++j) {
            //do_smt();
        }
    }
};

void oops() {
    int some_local_state = 0; // <-- reference to local variable
    func my_func(some_local_state);

    std::thread my_thread(my_func);
    my_thread.detach();
} // <-- here my_thread will call destructor (std::terminate)