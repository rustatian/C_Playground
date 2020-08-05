#include "main.h"
#include <cstdio>
#include <iostream>
#include <emscripten/emscripten.h>

EM_JS(void, call_alert,(),{
alert('hello world!');
throw 'all done';
})

extern "C" {
void EMSCRIPTEN_KEEPALIVE
myFunction(int argc, char **argv) {
    emscripten_run_script("alert('hi')");
}
}

int main(int argc, char **argv) {
    //call_alert();
}
