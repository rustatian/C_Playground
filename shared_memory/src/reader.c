//
// Created by valery on 2/19/20.
//

/** Compilation: gcc -o memreader memreader.c -lrt -lpthread **/
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include "../include/main.h"
#include <sys/time.h>

void report_and_exit(const char *msg) {
    perror(msg);
    exit(-1);
}

int main() {
    int fd = shm_open(BackingFile, O_RDWR, AccessPerms);  /* empty to begin */
    if (fd < 0) report_and_exit("Can't get file descriptor...");

    /* get a pointer to memory */
    caddr_t memptr = mmap(NULL,       /* let system pick where to put segment */
                          ByteSize,   /* how many bytes */
                          PROT_READ | PROT_WRITE, /* access protections */
                          MAP_SHARED, /* mapping visible to other processes */
                          fd,         /* file descriptor */
                          0);         /* offset: start at 1st byte */
    if ((caddr_t) -1 == memptr) report_and_exit("Can't access segment...");

    /* create a semaphore for mutual exclusion */
    sem_t *semptr = sem_open(SemaphoreName, /* name */
                             O_CREAT,       /* create the semaphore */
                             AccessPerms,   /* protection perms */
                             0);            /* initial value */
    if (semptr == (void *) -1) report_and_exit("sem_open");

    /* use semaphore as a mutex (lock) by waiting for writer to increment it */
    if (!sem_wait(semptr)) { /* wait until semaphore != 0 */
        int i;
        struct timeval stop, start;
        gettimeofday(&start, NULL);

        for (i = 0; i < 1000000; i++) {
//            int len = strlen(MemContents);

//            if (!sem_wait(semptr)) {
//                report_and_exit("sem_wait in cycle");
//            }

            for (i = 0; i < strlen(MemContents); i++) {
                write("/dev/null", memptr + i, 1); /* one byte at a time */
            }

        }

        gettimeofday(&stop, NULL);
        printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
        sem_post(semptr);
    }

    /* cleanup */
    munmap(memptr, ByteSize);
    close(fd);
    sem_close(semptr);
    unlink(BackingFile);
    return 0;
}