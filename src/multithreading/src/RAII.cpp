//
// Created by valery on 10/11/2019.
//

#include <thread>

class thread_guard {
    std::thread &t;
public:
    explicit thread_guard(std::thread &t_) : t(t_) {}

    ~thread_guard() {
        if (t.joinable()) {
            t.join();
        }
    }

    thread_guard(thread_guard const &) = delete;

    thread_guard &operator=(thread_guard const &) = delete;
};

class scoped_thread {
    std::thread t;
public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_)) {
        if (!t.joinable())
            throw std::logic_error("No thread");
    }

    ~scoped_thread() {
        t.join();
    }

    scoped_thread(scoped_thread const &) = delete;

    scoped_thread &operator=(scoped_thread const &) = delete;
};


struct func3 {
    int &i;

    explicit func3(int &i_) : i(i_) {}

    void operator()() {
        for (unsigned j = 0; j < 1000000; ++j) {
            //do_smt();
        }
    }
};

void f() {
    int some_local_state = 0;
    func3 my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);
    //do_smt_in_current_thread();
}