#ifndef PROCESS_H
#define PROCESS_H

#include "mem.h"
#include "atom.h"

typedef struct process_cfg_t {
    mem_t *mem;
    atom_t *atom;
} process_cfg_t;


void sub_process_oxygen(mem_t *mem, unsigned int atom_id);

process_t fork_process(unsigned int count, ATOM_TYPE type);

void main_process(mem_t *mem);

#endif //PROCESS_H
