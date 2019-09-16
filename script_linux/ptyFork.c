//
// Created by valery on 16/09/2019.
//

#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "string.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "ptyFork.h"
#include "pty_master_open.h"

#define MAX_SNAME 1000

pid_t ptyFork(int *masterFd, char *slaveName, size_t snLen, const struct termios *slaveTermios,
              const struct winsize *slaveWS) {
    int mfd, slaveFd, savedErrno;
    pid_t childPid;
    char slname[MAX_SNAME];

    mfd = ptyMasterOpen(slname, MAX_SNAME);
    if (mfd == -1) {
        return -1;
    }

    if (slaveName != NULL) { // this is slave name of the caller
        if (strlen(slname) < snLen) {
            strncpy(slaveName, slname, snLen);
        } else { // slave name was too small
            close(mfd);
            errno = EOVERFLOW;
            return -1;
        }
    }

    childPid = fork();
    if (childPid == -1) {
        savedErrno = errno;
        close(mfd);
        errno = savedErrno;
        return -1;
    }

    if (childPid != 0) {
        *masterFd = mfd;
        return childPid;
    }

    // for child

    if (setsid() == -1) {
        printf("error in setsid");
        _exit(1);
    }

    close(mfd);

    slaveFd = open(slname, O_RDWR);
    if (slaveFd == -1) {
        printf("error in open slname");
        _exit(1);
    }

#ifdef TIOCSCTTY // <----------- for BSD
    if (ioctl(slaveFd, TIOCSCTTY, 0) == -1) {
        printf("error in ioctl");
        _exit(1);
    }
#endif
    if (slaveTermios != NULL){
        if (tcsetattr(slaveFd, TCSANOW, slaveTermios) == -1) {
            printf("error tcsetattr");
            _exit(1);
        }
    }

    if (slaveWS != NULL) {
        if (ioctl(slaveFd, TIOCSCTTY, slaveWS) == -1) {
            if (tcsetattr(slaveFd, TCSANOW, slaveTermios) == -1) {
                printf("error ioctl(slaveFd, TIOCSCTTY, slaveWS)");
                _exit(1);
            }
        }
    }

    // duplicate pty slave to be child's stdin, stdout and stderr

    if (dup2(slaveFd, STDIN_FILENO) != STDIN_FILENO) {
        printf("error dup2 STDIN_FILENO");
        _exit(1);
    }

    if (dup2(slaveFd, STDOUT_FILENO) != STDOUT_FILENO) {
        printf("error dup2 STDOUT_FILENO");
        _exit(1);
    }

    if (dup2(slaveFd, STDERR_FILENO) != STDERR_FILENO) {
        printf("error dup2 STDERR_FILENO");
        _exit(1);
    }

    if(slaveFd > STDERR_FILENO) {
        close(slaveFd);
    }

    return 0;

}





