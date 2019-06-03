//
// Created by Valery Piashchynski on 2019-06-03.
//

#include <stddef.h>
#include "string.h"
#include "main.h"
#include "ctype.h"

int main(int argc, char **argv) {
    size_t const len = strlen(argv[0]); //compute the lenght

    char name[len + 1];

    memcpy(name, argv[0], len);

    name[len] = 0;





}