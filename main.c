#include <stdio.h>
#include "helpers.h"
#include "mem.h"
#include "process.h"

int main(int argc, char **argv) {
    args_t *args = parse_args(argc, argv);
    printf("%d\n", args->NH);

    mem_t *mem = mem_init();
    mem_fill(mem, args->NO, args->NH, args->TI, args->TB);

    main_process(mem);

    mem_destroy(mem);
}
