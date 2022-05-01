#include <stdlib.h>
#include <printf.h>
#include <unistd.h>
#include "process.h"
#include "helpers.h"

void sub_process_run(process_cfg_t *cfg) {
    unsigned int line = cfg->mem->line;
    unsigned int id = cfg->atom->id;
    ATOM_TYPE type = cfg->atom->type;

    printf("%du: %c %du: started\n", line, type, id);

    unsigned int atom_time = cfg->mem->atom_time;

    usleep(RAND_INT(atom_time));

    printf("%du: %c %du: going to queue\n", line, type, id);
}

