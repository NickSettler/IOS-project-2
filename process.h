#ifndef PROCESS_H
#define PROCESS_H

#include "mem.h"
#include "atom.h"

typedef struct process_cfg_t {
    mem_t *mem;
    atom_t *atom;
} process_cfg_t;

void sub_process_oxygen(mem_t *mem, atom_t *atom);

void sub_process_run(process_cfg_t *cfg);

#endif //PROCESS_H
