#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "semaphores.h"
#include "helpers.h"

void semaphores_init(mem_t *mem) {
    semaphores_unlink();

    semaphores_t *semaphores = malloc(sizeof(semaphores_t));
    if (semaphores == NULL) {
        ERROR
        exit(EXIT_FAILURE);
    }

    semaphores->output_sem = sem_open("output_sem", O_CREAT | O_EXCL, S_IRWXU, 1);

    if (semaphores->output_sem == SEM_FAILED) {
        ERROR
        exit(EXIT_FAILURE);
    }

    mem->semaphores = semaphores;
}

void semaphores_unlink() {
    sem_unlink("output_sem");
}

void semaphores_destroy(mem_t *mem) {
    semaphores_t *semaphores = mem->semaphores;

    int close_result = sem_close(semaphores->output_sem);

    if (close_result == -1) ERROR

    semaphores_unlink();

    free(semaphores);
}
