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
              std::forward<Args>(args)...) {}

    explicit joining_threads(std::thread t_) noexcept(true) : t(std::move(t_)) {}

    joining_threads(joining_threads &&other) noexcept(true) : t(std::move(other.t)) {}

    joining_threads &operator=(joining_threads &&other) noexcept {
        if (joinable()) {

        }
    }

    bool joinable() const noexcept {
        return t.joinable();
    }

    void join() {
        t.join();
    }

    void detach() {
        t.detach();
    }

    std::thread &as_thread() noexcept {
        return t;
    }

    [[nodiscard]] const std::thread &as_thread() const noexcept {
        return t;
    }
};