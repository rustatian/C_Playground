//
// Created by Valery Piashchynski on 2/10/19.
//

#include "debugger.h"
#include <string>
#include <vector>
#include <sstream>

debugger::debugger(std::string prog_name, pid_t pid) : m_prog_name{std::move(prog_name)}, m_pid{pid} {

}

void debugger::run() {
    int wait_status;
    auto options = 0;

    waitpid(m_pid, &wait_status, options);

    char *line = nullptr;
    while ((line = linenoise("minidbg> ")) != nullptr) {
        handle_command(line);
        linenoiseHistoryAdd(line);
        linenoiseFree(line);
    }
}

void debugger::handle_command(const std::string &line) {
    std::vector<std::string> args = split(line, ' ');

}


std::vector<std::string> debugger::split(const std::string &s, char delimiter) {
    std::vector<std::string> out{};
    std::stringstream ss{s};
    std::string item;

    while (std::getline(ss, item, delimiter)) {
        out.push_back(item);
    }

    return out;

}

bool debugger::is_prefix(const std::string &s, const std::string &of) {
    if(s.size() > of.size())
        return false;

    return std::equal(s.begin(), s.end(), of.begin());
}

//std::vector<std::string> split(const std::string &s, char delimeter) {
//    std::vector<std::string> out{};
//}