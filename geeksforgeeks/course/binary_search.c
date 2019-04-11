//
// Created by Valery Piashchynski on 2019-04-11.
//
#include <stdio.h>


int binary_search(int arr[], int low, int high, int key) {
    if (high < low) {
        return -1;
    }

    int mid = (low + high) / 2;
    if (key == arr[mid]) {
        return mid;
    }
    if (key > arr[mid]) {
        return binary_search(arr, (mid + 1), high, key);
    }
    return binary_search(arr, (mid - 1), high, key);
}

