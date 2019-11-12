//
// Created by Valery Piashchynski on 11/12/19.
//

#include <thread>
#include "../include/joining_threads.hpp"

class joining_threads {
    std::thread t;
public:
    joining_threads() noexcept(true) = default;

    template<typename Callable, typename ... Args>
    explicit joining_threads(Callable &&func, Args &&... args):
            t(std::forward<Callable>(func),
              std::forward<Args>(args)...) {

    }
};