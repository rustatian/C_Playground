#include "../include/Walker.hpp"
#include <iostream>
#include <filesystem>
#include <boost/program_options.hpp>

namespace opt = boost::program_options;

int main(int argc, char *argv[]) {
    opt::options_description desc("All options");

    desc.add_options()
            ("path", opt::value<std::string>(), "path to the folder with git repositories");


    opt::variables_map vm;
    opt::store(opt::parse_command_line(argc, argv, desc), vm);

    try {
        opt::notify(vm);
    } catch (const opt::required_option &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 2;
    }


    std::cout << "path is: " << vm["path"].as<std::string>() << std::endl;

    Walker w{};

    for (const std::filesystem::directory_entry &entry: std::filesystem::directory_iterator(
            vm["path"].as<std::string>())) {
        if (entry.is_directory()) {
            w.add_repo(entry.path().string());
        }
    }

    w.pull_changes();
    w.push_origin();
    return EXIT_SUCCESS;
}