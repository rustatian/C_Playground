#include <stdbool.h>
#include "stdio.h"
#include "binary_search.h"


int main() {
    int m;
    scanf("%d", &m);
    if (m > 12) {
        printf("%d", -1);
        return 0;
    }

    if ((m % 2) == 0) {
        printf("30");
        return 0;
    }

    printf("31");



    return 0;

//    int arr[] = {5, 6, 7, 8, 9, 10};
//    int n, key;
//    n = sizeof(arr) / sizeof(arr[0]);
//    key = 10;
//
//    printf("Index: %d\n", binary_search(arr, 0, n, key));
//    return 0;
}


