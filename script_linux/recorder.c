//
// Created by valery on 17/09/2019.
//

#include "recorder.h"
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include "string.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define BUF_SIZE 256
#define MAX_SNAME 1000

struct termios ttyOrigin;

static void ttyReset(void) {
    if (tcsetattr(STDIN_FILENO, TCSANOW, &ttyOrigin) == -1) {
        printf("error while setting origin");
        _exit(1);
    }
}

int main(int argc, char *argv[]) {
    char slaveName[MAX_SNAME];
    char *shell;
    int masterFd, recorderFd;
    struct winsize ws;
    fd_set inFds;
    

}


































