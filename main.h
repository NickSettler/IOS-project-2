#ifndef MAIN_H
#define MAIN_H

#include "vector.h"

/**
 * @struct semaphores_t
 * Semaphores for all processes
 */
typedef struct semaphores_t {
    /* Semaphore for output to the console */
    sem_t *output_sem;
} semaphores_t;

/**
 * @struct memory_t
 * Shared memory for all processes
 */
typedef struct mem_t {
    /* Shared memory id */
    int mem_id;
    /* Shared memory pointer */
    void *mem_addr;
    /* Current output line */
    unsigned int line;
    unsigned int current_h;
    /* Number of hydrogen */
    unsigned int h_count;
    unsigned int current_o;
    /* Number of oxygen */
    unsigned int o_count;
    unsigned int current_m;
    /* Max time needed to create atom */
    unsigned int atom_time;
    /* Max time needed to create molecule */
    unsigned int molecule_time;
    /* Vector of oxygen atoms */
    vector_t *o_vector;
    /* Vector of hydrogen atoms */
    vector_t *h_vector;
    /* Semaphores */
    semaphores_t *semaphores;
} mem_t;

#endif
