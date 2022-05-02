#ifndef MAIN_H
#define MAIN_H

#include <semaphore.h>
#include <stdbool.h>
#include "vector.h"

typedef struct args_t {
    int NO, NH, TI, TB;
} args_t;

typedef enum MESSAGE_TYPE {
    ATOM_CREATED,
    ATOM_TO_QUEUE,
    ATOM_FROM_QUEUE,
    ATOM_READY,
    ATOM_INSUFFICIENT_H,
    ATOM_INSUFFICIENT_O,
} MESSAGE_TYPE;

typedef enum ATOM_TYPE {
    OXYGEN = 'O',
    HYDROGEN = 'H',
} ATOM_TYPE;

typedef struct atom_t {
    unsigned int id;
    ATOM_TYPE type;
    bool ready;
} atom_t;

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
