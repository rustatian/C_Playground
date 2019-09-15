//
// Created by valery on 15/09/2019.
//

#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int posix_openpt(int flags) {
    return open("/dev/ptmx", flags);
}

int main() {

}