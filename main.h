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

typedef struct atom_t {
    uint id;
    ATOM_TYPE type;
} atom_t;

typedef struct semaphores_t {
    /* Semaphore for output to the console */
    sem_t *output_sem;
    /* Semaphore for hydrogen atom creation */
    sem_t *h_sem;
    /* Semaphore for oxygen atom creation */
    sem_t *o_sem;
    sem_t *ready_sem;
    sem_t *created_sem;
    sem_t *creating_sem;
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
    uint current_h;
    uint current_o;
    id_t m_id;
    uint current_m_h;
    uint current_m;
    /* Output file */
    FILE *output_file;
} mem_t;

typedef struct process_t {
    pid_t pid;
    atom_t atom;
    bool extra_info;
} process_t;

#endif
