#ifndef HELPERS_H
#define HELPERS_H

/**
 * Returns random number between 0 and n
 * @param n upper bound
 */
#define RAND_INT(n) (rand() % (n))

typedef struct args_t {
    int NO, NH, TI, TB;
} args_t;

/**
 * Parsing arguments
 * @param argc - number of arguments
 * @param argv - array of arguments
 * @return - parsed arguments
 */
args_t* parse_args(int argc, char **argv);

void print_error(char *format, ...) __printflike(1, 2);

#endif //HELPERS_H
