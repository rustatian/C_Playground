//
// Created by valery on 7/12/19.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "main.h"


using namespace std;

vector<int> vec;

struct Record {
    string Name;
};

double square(double x) {
    return x * x;
}

void copy_fct() {
    int v1[10] = {1, 2, 3, 4, 5, 6, 7};

    int v2[10];

    for (auto i = 0; i < (sizeof(v1) / sizeof(v1[0])); i++) {
        v2[i] = v1[i];
    }
}

int main() {
    copy_fct();

    constexpr int dvm = 12;
    int var = 17;
    const double sqv = sqrt(var);

    vector<double> v{1, 2, 3};

    string motto{"whaaat???"};


    auto p = new Record{"hume"};
    p->Name = "rew";


    std::cout << "Hello, Word!\n";


    char fv[6];

    char *tp = &fv[3];


    return 0;
}