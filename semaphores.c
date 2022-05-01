#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "semaphores.h"

void semaphores_init(mem_t *mem) {
    semaphores_t *semaphores = malloc(sizeof(semaphores_t));
    if (semaphores == NULL) {
        fprintf(stderr, "semaphores_init: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    semaphores->output_sem = sem_open("output_sem", O_CREAT | O_EXCL, S_IRWXU, 0);
}
