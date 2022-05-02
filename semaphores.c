#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "semaphores.h"
#include "helpers.h"

void semaphores_init(mem_t *mem) {
    semaphores_t *semaphores = malloc(sizeof(semaphores_t));
    if (semaphores == NULL) {
        print_error("%s:%d %s\n", __FILE__, __LINE__, strerror(errno));
        exit(EXIT_FAILURE);
    }

    semaphores->output_sem = sem_open("output_sem", O_CREAT | O_EXCL, S_IRWXU, 0);

    if (semaphores->output_sem == SEM_FAILED) {
        print_error("%s:%d %s\n", __FILE__, __LINE__, strerror(errno));
        exit(EXIT_FAILURE);
    }

    mem->semaphores = semaphores;
}

void semaphores_destroy(mem_t *mem) {
    semaphores_t *semaphores = mem->semaphores;

    int close_result = sem_close(semaphores->output_sem);

    if (close_result == -1)
        print_error("%s:%d %s\n", __FILE__, __LINE__, strerror(errno));

    int unlink_result = sem_unlink("output_sem");

    if (unlink_result == -1)
        print_error("%s:%d %s\n", __FILE__, __LINE__, strerror(errno));

    free(semaphores);
}
