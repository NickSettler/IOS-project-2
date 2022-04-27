#ifndef MEM_H
#define MEM_H

#include <sys/semaphore.h>
#include "main.h"

typedef struct mem_t {
    int mem_id;
    void *mem_addr;
    unsigned int line;
    unsigned int current_h;
    unsigned int h_count;
    unsigned int current_o;
    unsigned int o_count;
    unsigned int m_count;
    unsigned int atom_time;
    unsigned int molecule_time;
} mem_t;

/**
 * Initialize memory
 * @return
 */
mem_t *mem_init();

void mem_fill(mem_t *mem, int NO, int NH, int TI, int TB);

/**
 * Destroy memory
 * @param mem - memory to destroy
 */
void mem_destroy(mem_t *mem);

#endif //MEM_H
