#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

args_t *parse_args(int argc, char **argv) {
    args_t *args = malloc(sizeof(args_t));

    if (argc < 5) {
        fprintf(stderr, "Usage: %s NO NH TI TB\n", argv[0]);
        exit(1);
    }

    unsigned long NO = strtol(argv[1], NULL, 10);
    unsigned long NH = strtol(argv[2], NULL, 10);
    unsigned long TI = strtol(argv[3], NULL, 10);
    unsigned long TB = strtol(argv[4], NULL, 10);

    if (NO < 0 || NH < 0 || TI < 0 || TB < 0) {
        fprintf(stderr, "Arguments must be grater 0\n");
        exit(1);
    }

    if (TI > 1000 || TB > 1000) {
        fprintf(stderr, "TI and TB must be lower than 1000\n");
        exit(1);
    }

    args->NO = (int) NO;
    args->NH = (int) NH;
    args->TI = (int) TI;
    args->TB = (int) TB;

    return args;
}
