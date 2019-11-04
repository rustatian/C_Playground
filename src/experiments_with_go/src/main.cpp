//
// Created by valery on 11/4/19.
//

#include <iostream>
#include "../include/main.hpp"
#include "../include/awesome.h"
#include <benchmark/benchmark.h>


static void BM_GOlangInvokation(benchmark::State &state) {
    GoInt a = 12;
    GoInt b = 99;

    std::cout << "invoking..." << std::endl;

    auto c = Add(a, b);

    std::cout << "result: " << c << std::endl;
}

BENCHMARK(BM_GOlangInvokation);

BENCHMARK_MAIN();