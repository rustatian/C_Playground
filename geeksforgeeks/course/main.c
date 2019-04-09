//
// Created by Valery Piashchynski on 2019-04-09.
//

#include "main.h"
#include <stdio.h>

float roundddd(float var) {
    // we use array of chars to store number
    // as a string.
    char str[20];

    // Print in string the value of var
    // with two decimal point
    sprintf(str, "%.2f", var);

    // scan string value in var
    sscanf(str, "%f", &var);

    return var;
}

int main() {
    float a;
    char ch;

    scanf("%f", &a);
    scanf(" %c", &ch);


    printf("%.2f %d", a, ch);


    return 0;
}

