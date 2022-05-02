#ifndef HELPERS_H
#define HELPERS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include "main.h"
#include "process.h"

#define ERROR print_error("%s:%d %s\n", __FILE__, __LINE__, strerror(errno));

#define __printflike__ __attribute__((format(printf, 1, 2)))
/**
 * Returns random number between 0 and n
 * @param n upper bound
 */
#define RAND_INT(n) (rand() % (n))

#define OUTPUT_FILE_NAME "proj2.out"
#define OUTPUT_FILE_MODE "w"

/**
 * Parsing arguments
 * @param argc - number of arguments
 * @param argv - array of arguments
 * @return - parsed arguments
 */
args_t *parse_args(int argc, char **argv);

void print_error(char *format, ...) __printflike__;

FILE *open_output();

void close_output(FILE *output);

void output_to_file(mem_t *mem, MESSAGE_TYPE type, process_t *process);

#endif //HELPERS_H
