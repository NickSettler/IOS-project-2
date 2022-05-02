#ifndef MEM_H
#define MEM_H

#include <semaphore.h>
#include "main.h"
#include "vector.h"
#include "semaphores.h"

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
