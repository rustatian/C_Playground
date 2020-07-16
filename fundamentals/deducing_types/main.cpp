#include <cstdlib>
#include "main.h"

template<typename T>
void f(T &param); // param is reference

int main() {
    int x = 27; // x is an int
    const int cx = x; // cx is a const int
    const int &rx = x; // rx is a reference to x as a const int

    f(x); // T is int, param's type is int&
    f(cx); // T is const int, param's type is const int&
    f(rx); // T is const int, param's type is const int&

    return EXIT_SUCCESS;
}

/*
 * template<typename T>
 * void f(ParamType param);
 *
 * f(expr); // <----- deduce T and ParamType from expr
 */