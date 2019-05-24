#include <lzma.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct {
    long key;
} Record;


float *myFunc(size_t n) {
    //reserve storage
    double *dPtr = malloc(sizeof(double));
    if(dPtr == NULL) {
        return NULL;
    } else { // got the memory, use it
        *dPtr = 0.07;
    }

    Record *rPtr;
    // get the storage for two objects of type Record
    if ((rPtr = malloc(2 * sizeof(Record))) == NULL) {
        // insufficient memory error
        return NULL;
    }

    float *fPtr = malloc(n * sizeof(float));
    if (fPtr == NULL) {
        return NULL;
    }
    return fPtr;

}

int main() {
    printf("Storage sizel");

    printf("The type char is %s. \n\n", CHAR_MIN < 0 ? "signed" : "unsigned");

}
