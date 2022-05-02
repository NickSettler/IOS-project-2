#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "helpers.h"

args_t *parse_args(int argc, char **argv) {
    args_t *args = malloc(sizeof(args_t));

    if (argc < 5) {
        print_error("Not enough arguments\n"
                    "Usage: ./%s NO NH TI TB\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    long NO = strtol(argv[1], NULL, 10);
    long NH = strtol(argv[2], NULL, 10);
    long TI = strtol(argv[3], NULL, 10);
    long TB = strtol(argv[4], NULL, 10);

    if (NO < 0 || NH < 0 || TI < 0 || TB < 0)
        print_error("Arguments must be grater 0\n"
                    "Usage: ./%s NO NH TI TB\n", argv[0]);

    if (TI > 1000 || TB > 1000)
        print_error("TI and TB must be lower than 1000\n"
                    "Usage: ./%s NO NH TI TB\n", argv[0]);

    args->NO = (int) NO;
    args->NH = (int) NH;
    args->TI = (int) TI;
    args->TB = (int) TB;

    return args;
}

void print_error(char *format, ...) {
    va_list strings;
    va_start(strings, format);

    fprintf(stderr, "[ERROR] ");
    vfprintf(stderr, format, strings);

    va_end(strings);
}

