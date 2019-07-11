#include <stdio.h>
#include <time.h>

double square(double x) {
    return x * x;
}

int main() {
    printf("num is: %f\n", square(1.5));

    struct timespec tim, tim2;
    tim.tv_sec = 5;
    tim.tv_nsec = 0;

    if (nanosleep(&tim, &tim2) < 0) {
        printf("Nano sleep system call failed \n");
        return -1;
    }

    printf("Nano sleep successfull \n");

    return 0;
}