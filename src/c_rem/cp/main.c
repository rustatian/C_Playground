#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include "main.h"

#define PERMS 0666

int main(int argc, char *argv[]) {
    int f1, f2, n;
    char buf[BUFSIZ];
    if (argc != 3) {
        printf("Usage: cp [from] [to]");
        return 1;
    }

    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
        printf("cp: can't open file %s", argv[1]);
        return 1;
    }

    if ((f2 = creat(argv[2], PERMS)) == -1) {
        printf("cp: can't create file %s", argv[2]);
        return 1;
    }


    while ((n = read(f1, buf, BUFSIZ)) > 0) {
        if (write(f2, buf, n))
            printf("cp: write error on file %s", argv[2]);
    }

    return 0;
}