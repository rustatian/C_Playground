//
// Created by valery on 15/09/2019.
//
#define _XOPEN_SOURCE 600

#include <stdlib.h>
#include <fcntl.h>
#include "pty_master_open.h"

int ptyMasterOpen(char *slaveName, size_t snLen) {
    int masterFd, savedErrno;

    char *p;

    masterFd = posix_openpt(O_RDWR | O_NOCTTY);
    if (masterFd == 1) {
        return -1;
    }
}