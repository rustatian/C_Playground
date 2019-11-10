//
// Created by valery on 20/10/2019.
//

#include "walker.hpp"
#include <string>
#include <iostream>
#include <filesystem>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <thread>
#include <future>

// RAII idiom
class thread_guard {
    std::thread &t;
public:
    explicit thread_guard(std::thread& t_) : t(t_){}
    ~thread_guard(){
        if(t.joinable()) {
            t.join();
        }
    }

    // assignment operator is marked as deleted
    thread_guard(thread_guard const&) = delete;
    // copy operator also deleted
    thread_guard &operator=(thread_guard const&) = delete; // operator = that returns a reference
};

void process_git_request(const std::filesystem::directory_entry &entry, const std::string &command) {
    std::cout << "entering dir: " << entry.path().string() << std::endl;

    char cstr[entry.path().string().size() + 1];
    // copy the string
    strcpy(cstr, entry.path().string().c_str());

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
    std::cout << "dir: " << entry.path().string() << " result: " << result << std::endl;

    try {
        pclose(pipe);
    } catch (...) {
        throw;
    }
}

void run_git_command(const std::string &command, const std::string &root) {
    for (const std::filesystem::directory_entry &entry: std::filesystem::directory_iterator(root)) {
        if (entry.is_directory()) {
            std::thread th(process_git_request, entry, command);
            thread_guard g(th);
        }
    }
}

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

    if (argc > 4) {
        throw std::runtime_error("wrong number of parameters");
    }

    // git add . && git commit -m "$(curl -s http://whatthecommit.com/index.txt)" && git push
    // assume that path, pull and push provided
    if (argc == 4) {
        std::cout << "EXECUTING: " << argv[2] << " AND: " << argv[3] << std::endl;
        run_git_command("git pull", argv[1]);
        run_git_command("git add . && git commit -m \"$(curl -s http://whatthecommit.com/index.txt)\" && git push",
                        argv[1]);
        // only pull or push
    } else if (argc == 3) {
        run_git_command(argv[2], argv[1]);
    }


    std::cout << "start searching dirs in: " << argv[1] << std::endl;
    char *root = argv[1];


    return 0;
}


























