#include "../include/lambda.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <cassert>

auto vals = std::vector<int>{1, 3, 2, 5, 4};

// look for the number
auto three = 3;

auto num_threes = std::count(vals.begin(), vals.end(), three);
// num_three is 1

auto is_above_3 = [](int v) {
    return v > 3;
};

auto num_above_3 = std::count_if(vals.begin(), vals.end(), is_above_3);
// num_above_3 is 2

auto num_3 = std::count(vals.begin(), vals.end(), 3);
auto num_above_3_new = std::count_if(vals.begin(), vals.end(), [](int v) {
    return v > 3;
});

auto count_value_above(const std::vector<int> &vals, int th) {
    auto is_above = [th](int v) { // or [&th]
        return v > th;
    };
    return std::count_if(vals.begin(), vals.end(), is_above);


}

/////////////// LAMBDA AND CLASS /////////////////

//capture by value

//auto th = 3;
//auto is_above = [th](int v) {
//    return v > th;
//};
//
//auto test = is_above(5);

// class
auto th = 3;

class IsAbobe {
public:
    IsAbobe(int th) : th{th} {}

    auto operator()(int v) const {
        return v > th;
    }

private:
    int th{};
};

auto is_above = IsAbobe{th};
auto test = is_above(5);

/// INITIALIZING VARIABLES IN CAPTURE

auto func = [c = std::list<int>{4, 2}]() {
    for (auto v: c) {
        std::cout << v;
    }
};


void fff() {
    func(); // output --> 42
}

// --> class

class Func {
public:
    Func() : c{4, 2} {}

    auto operator()() const -> void {
        for (auto v: c)
            std::cout << v;
    }

private:
    std::list<int> c;
};

// mutating lambda

auto funcc() {
    auto v = 7;
    auto lambda = [v]() mutable {
        std::cout << v << " ";
        ++v;
        std::cout << v << " ";
    };

    assert(v == 7);
    lambda();
    lambda();
    assert(v == 7);
}

// capture all
//[=] -- all variables by value
//[&] -- all variables by reference

int main() {
    funcc();
}




















