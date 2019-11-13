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
            join();
        }
        t = std::move(other.t);
        return *this;
    }

    joining_threads&operator=(std::thread other) noexcept(true) {
        if(joinable()) {
            join();
        }
        t = std::move(other);
        return *this;
    }
    ~joining_threads() noexcept {
        if(joinable())
            join();
    }

    void swap(joining_threads &other) noexcept {
        t.swap(other.t);
    }

    std::thread::id get_id() const noexcept {
        return t.get_id();
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

    [[nodiscard]] const std::thread& as_thread() const noexcept {
        return t;
    }
};