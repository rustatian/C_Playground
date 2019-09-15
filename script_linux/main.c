//
// Created by valery on 15/09/2019.
//

#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "pty_master_open.h"

int posix_openpt(int flags) {
    return open("/dev/ptmx", flags);
}

int main() {
    int pty = -1;
    char slaveName[100];
    pty = ptyMasterOpen(slaveName, 11);
    printf("%d", pty);
}