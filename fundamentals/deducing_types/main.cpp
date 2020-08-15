#include <cstdlib>
#include <iostream>
#include "main.h"
#include <concepts>

template<typename T>
void f(T &param); // param is reference

template<typename T>
void f2(const T &param);

template<typename T>
void f3(T *param); // param now is a pointer

template<typename T>
void f4(T &&param); // universal reference

using namespace std::literals;

// Declaration of the concept "Hashable", which is satisfied by
// any type 'T' such that for values 'a' of type 'T',
// the expression std::hash<T>{}(a) compiles and its result is convertible to std::size_t
template<typename T>
concept Hashable = requires(T a) {
    { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};

struct meow {};

template<Hashable T>
void ff(T); // constrained C++20 function template

int main() {
    int x = 27; // x is an int
    const int cx = x; // cx is a const int
    const int &rx = x; // rx is a reference to x as a const int

//    f(x); // T is int, param's type is int&
//    f(cx); // T is const int, param's type is const int&
//    f(rx); // T is const int, param's type is const int&
//
//
//    int y = 27; // T is int, param's type is const int&
//    const int cy = x; // T is int, param's type is const int&
//    const int &ry = x; // T is int, param's type is const int&
//
//    f2(y);
//    f2(cy);
//    f2(ry);
//
//    int z = 27;
//    const int *zy = &x;
//
//    f3(&x);
//    f3(zy);
//
    return EXIT_SUCCESS;
}

/*
 * template<typename T>
 * void f(ParamType param);
 *
 * f(expr); // <----- deduce T and ParamType from expr
 */