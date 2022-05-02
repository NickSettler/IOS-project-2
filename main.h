#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <semaphore.h>
#include <stdbool.h>

typedef struct args_t {
    uint NO, NH, TI, TB, EH, EO;
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

/**
 * @struct atom_t
 * Atom structure
 */
typedef struct atom_t {
    /* ID of the atom */
    uint id;
    /* Type of the atom */
    ATOM_TYPE type;
} atom_t;

/**
 * @struct semaphores_t
 * Semaphores used in the program
 */
typedef struct semaphores_t {
    /* Semaphore for output to the console */
    sem_t *output_sem;
    /* Semaphore for hydrogen atom creation */
    sem_t *h_sem;
    /* Semaphore for oxygen atom creation */
    sem_t *o_sem;
    /* Semaphore for detecting when atom is ready */
    sem_t *ready_sem;
    /* Semaphore for detecting molecule creation */
    sem_t *creating_sem;
    /* Semaphore for detecting insufficient resources */
    sem_t *stop_extra_sem;
} semaphores_t;

/**
 * @struct memory_t
 * Shared memory for all processes
 */
typedef struct mem_t {
    /* Shared memory id */
    int mem_id;
    /* Current output line */
    uint line;
    /* Current hydrogen to work with */
    uint current_h;
    /* Current oxygen to work with */
    uint current_o;
    /* ID of current molecule */
    id_t m_id;
    /* Number of hydrogen atoms of the molecule */
    uint current_m_h;
} mem_t;

/**
 * @struct process_t
 * Process structure
 */
typedef struct process_t {
    atom_t atom;
    bool extra_info;
} process_t;

#endif
