#include <stdio.h>
#include "helpers.h"
#include "mem.h"

int main(int argc, char **argv) {
    args_t *args = parse_args(argc, argv);
    printf("%d\n", args->NH);

    mem_t *mem = mem_init();
    mem_fill(mem, args->NO, args->NH, args->TI, args->TB);

    mem_destroy(mem);
}
