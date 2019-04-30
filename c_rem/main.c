#include "stdio.h"
#include "stdlib.h"
#include <sys/syscall.h>
#include <zconf.h>

int getchar(void) {
    char c;
    return (read(0,&c, 1)) ? (unsigned char) c : EOF;
}


int main() {
    char buf[BUFSIZ];
    int n;

    getchar();


    while((n = read(0, buf, BUFSIZ)) > 0) {
        write(1, buf, n);
    }

}