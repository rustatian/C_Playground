#include "stdio.h"
#include "binary_search.h"


int main() {

    int arr[] = {5, 6, 7, 8, 9, 10};
    int n, key;
    n = sizeof(arr) / sizeof(arr[0]);
    key = 10;

    printf("Index: %d\n", binary_search(arr, 0, n, key));
    return 0;
}


