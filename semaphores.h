#ifndef SEMAPHORES_H
#define SEMAPHORES_H

#include <semaphore.h>
#include "main.h"

#define SEM_INIT(k, v)(sem_open(k, O_CREAT | O_WRONLY, 0666, v))

#define OUTPUT_SEM "output_sem"
#define H_SEM "h_sem"
#define O_SEM "o_sem"
#define READY_SEM "ready_sem"
#define CREATING_SEM "creating_sem"
#define STOP_EXTRA_SEM "stop_extra_sem"

/**
 * Initializes semaphores
 * @param semaphores - struct of semaphores
 */
void semaphores_init(semaphores_t *semaphores);

/**
 * Unlinks semaphores
 */
void semaphores_unlink();

/**
 * Deletes semaphores
 * @param semaphores - struct of semaphores
 */
void semaphores_destroy(semaphores_t *semaphores);

#endif //SEMAPHORES_H
