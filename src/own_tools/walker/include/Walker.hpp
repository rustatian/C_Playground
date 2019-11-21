//
// Created by valery on 20/10/2019.
//

#ifndef PLAYGROUND_WALKER_HPP
#define PLAYGROUND_WALKER_HPP


#include <string>
#include <utility>
#include <vector>

class Walker {
public:
    Walker() = default;;

    Walker &operator()() = delete;

    void add_path(const std::string& path);

    void pull_repo() noexcept(false);

    void push_origin() noexcept(false);


    ~Walker() {
        paths_.clear();
        paths_.shrink_to_fit();
    }

private:
    void executor(const std::string &path, const std::string &command);
    std::vector<std::string> paths_;
    const std::string PULL_COMMAND_ = "git pull";
    const std::string PUSH_COMMAND_ = "git add . && git commit -m \"$(curl -s http://whatthecommit.com/index.txt)\" && git push";
};


#endif //PLAYGROUND_WALKER_HPP
