#ifndef MEM_H
#define MEM_H

#include <semaphore.h>
#include "main.h"
#include "helpers.h"
#include "semaphores.h"

/**
 * Initialize memory
 * @return
 */
mem_t *mem_init();

void mem_fill(mem_t *mem);

/**
 * Destroy memory
 * @param mem - memory to destroy
 */
void mem_destroy(mem_t *mem);

#endif //MEM_H
