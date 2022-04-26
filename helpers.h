#ifndef HELPERS_H
#define HELPERS_H

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

#endif //HELPERS_H
