#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "semaphores.h"
#include "helpers.h"

void semaphores_init(semaphores_t *semaphores) {
    if (semaphores == NULL) {
        ERROR
        exit(EXIT_FAILURE);
    }

    if ((semaphores->output_sem = SEM_INIT(OUTPUT_SEM, 0)) == SEM_FAILED) {
        ERROR
        exit(EXIT_FAILURE);
    }

    if ((semaphores->h_sem = SEM_INIT(H_SEM, 0)) == SEM_FAILED) {
        ERROR
        exit(EXIT_FAILURE);
    }

    if ((semaphores->o_sem = SEM_INIT(O_SEM, 0)) == SEM_FAILED) {
        ERROR
        exit(EXIT_FAILURE);
    }

    if ((semaphores->ready_sem = SEM_INIT(READY_SEM, 0)) == SEM_FAILED) {
        ERROR
        exit(EXIT_FAILURE);
    }

    if ((semaphores->created_sem = SEM_INIT(CREATED_SEM, 0)) == SEM_FAILED) {
        ERROR
        exit(EXIT_FAILURE);
    }

    if ((semaphores->creating_sem = SEM_INIT(CREATING_SEM, 0)) == SEM_FAILED) {
        ERROR
        exit(EXIT_FAILURE);
    }

    if ((semaphores->stop_extra_sem = SEM_INIT(STOP_EXTRA_SEM, 0)) == SEM_FAILED) {
        ERROR
        exit(EXIT_FAILURE);
    }

    semaphores_unlink();
}

void semaphores_unlink() {
    sem_unlink(OUTPUT_SEM);
    sem_unlink(H_SEM);
    sem_unlink(O_SEM);
    sem_unlink(READY_SEM);
    sem_unlink(CREATED_SEM);
    sem_unlink(CREATING_SEM);
    sem_unlink(STOP_EXTRA_SEM);

}

void semaphores_destroy(semaphores_t *semaphores) {
    int close_result = sem_close(semaphores->output_sem) ||
            sem_close(semaphores->h_sem) ||
            sem_close(semaphores->o_sem) ||
            sem_close(semaphores->ready_sem) ||
            sem_close(semaphores->created_sem) ||
            sem_close(semaphores->creating_sem) ||
            sem_close(semaphores->stop_extra_sem);

    if (close_result == -1) ERROR

    semaphores_unlink();
}
