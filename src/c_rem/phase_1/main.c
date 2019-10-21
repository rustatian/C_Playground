#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
    double A[5] = {
            [0] = 9.0,
            [1]= 2.9,
            [4]= 3.E+25,
            [3] = .00007,
    };

 
    
    for (size_t i = 0; i < sizeof(A)/ sizeof(A[0]); ++i) {
        printf("element %zu is %g, \tits square is %g\n",
               i,
               A[i], A[i] * A[i]);
    }

    return EXIT_SUCCESS;
}
