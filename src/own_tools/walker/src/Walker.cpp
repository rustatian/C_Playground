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
            w.add_path(entry.path().string());
        }
    }

    w.pull_repo();
    w.push_origin();
}


void Walker::pull_repo() noexcept(false) {
    for (auto &path : paths_){
        Walker::executor(path, Walker::PULL_COMMAND_);
    }
}

void Walker::push_origin() noexcept(false) {
    for (auto &path : paths_) {
        Walker::executor(path, Walker::PUSH_COMMAND_);
    }
}

void Walker::add_path(const std::string& path) {
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


    // buffer
    char buffer[256];
    // result string
    std::string result;

    // open a pipe
    // git add . && git commit -m "$(curl -s http://whatthecommit.com/index.txt)" && git push
    // assume that path, pull and push provided
    FILE *pipe = popen(command.c_str(), "r");
    if (!pipe) {
        throw std::runtime_error("popen failed");
    }

    // get data from process and put in the buffer
    try {
        while (fgets(buffer, sizeof buffer, pipe) != nullptr) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }

    // print the result
    std::cout << "dir: " << path << " result: " << result << std::endl;

    try {
        pclose(pipe);
    } catch (...) {
        throw;
    }
}
