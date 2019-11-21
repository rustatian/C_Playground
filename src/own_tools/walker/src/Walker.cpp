//
// Created by valery on 20/10/2019.
//

#include "../include/Walker.hpp"
#include <string>
#include <iostream>
#include <filesystem>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <thread>
#include <future>
#include <vector>

// RAII idiom
class thread_guard {
    std::thread &t;
public:
    explicit thread_guard(std::thread &t_) : t(t_) {}

    ~thread_guard() {
        if (t.joinable()) {
            t.join();
        }
    }

    // assignment operator is marked as deleted
    thread_guard(thread_guard const &) = delete;

    // copy operator also deleted
    thread_guard &operator=(thread_guard const &) = delete; // operator = that returns a reference
};


void Walker::pull_repos() noexcept(false) {
    for (auto &path : paths_){
        Walker::executor(path, Walker::PULL_COMMAND_);
    }
}

void Walker::push_origin() noexcept(false) {
    for (auto &path : paths_) {
        Walker::executor(path, Walker::PUSH_COMMAND_);
    }
}

void Walker::add_repo(const std::string& path) {
    paths_.push_back(path);
}

void Walker::executor(const std::string &path, const std::string &command) {
    std::cout << "entering dir: " << path << std::endl;

    char cstr[path.size() + 1];
    // copy the string
    strcpy(cstr, std::string(path).c_str());

    try {
        chdir(cstr);
    } catch (...) {
        throw;
    }

    std::array<char, 256> buffer{};
    // result string
    std::string result;

    // open a pipe
    // git add . && git commit -m "$(curl -s http://whatthecommit.com/index.txt)" && git push
    // assume that path, pull and push provided

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    // print the result
    std::cout << "dir: " << path << " result: " << result << std::endl;

}
