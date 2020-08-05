#include "main.h"
#include <cstdio>
#include <iostream>
#include <emscripten/emscripten.h>

int main(int argc, char **argv) {
    printf("Hello World\n");
}


extern "C" {
void EMSCRIPTEN_KEEPALIVE
myFunction(int argc, char **argv) {
    std::cout << "MyFunction Called" << std::endl;
}
}
