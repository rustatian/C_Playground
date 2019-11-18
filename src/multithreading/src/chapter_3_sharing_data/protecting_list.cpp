//
// Created by valery on 11/18/19.
//
#include <list>
#include <mutex>
#include <algorithm>

std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_value) {
    std::scoped_lock<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
    // ~guard destructor here
}

bool list_contains(int value_to_find) {
    std::scoped_lock<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}


int main(int, char **) {

}