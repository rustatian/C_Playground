#include <cstdlib>
#include <iostream>
#include "main.h"

template<typename T>
void f(T &param); // param is reference

template<typename T>
void f2(const T &param);

template<typename T>
void f3(T *param); // param now is a pointer

template<typename T>
void f4(T &&param); // universal reference

template<typename T, int N>
struct Buffer {
    using value_type = T;

    constexpr int size() {
        return N;
    }
};

int main() {
    Buffer<char, 128> glob;
    auto a = glob.size();
    auto b = glob.size();
    std::cout << a << std::endl;
    int x = 27; // x is an int
    const int cx = x; // cx is a const int
    const int &rx = x; // rx is a reference to x as a const int

    f(x); // T is int, param's type is int&
    f(cx); // T is const int, param's type is const int&
    f(rx); // T is const int, param's type is const int&


    int y = 27; // T is int, param's type is const int&
    const int cy = x; // T is int, param's type is const int&
    const int &ry = x; // T is int, param's type is const int&

    f2(y);
    f2(cy);
    f2(ry);

    int z = 27;
    const int *zy = &x;

    f3(&x);
    f3(zy);

    return EXIT_SUCCESS;
}

/*
 * template<typename T>
 * void f(ParamType param);
 *
 * f(expr); // <----- deduce T and ParamType from expr
 */