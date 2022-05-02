#include <stdlib.h>
#include <printf.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <semaphore.h>
#include <stdio.h>
#include "process.h"
#include "helpers.h"

void sub_process_oxygen(mem_t *mem, unsigned int atom_id) {
    int wait_result = sem_wait(mem->semaphores->output_sem);
    if (wait_result == -1) {
        ERROR
        exit(EXIT_FAILURE);
    }

    mem->line += 1;
    printf("%d: %c %d: started\n", mem->line, OXYGEN, atom_id);
    sem_post(mem->semaphores->output_sem);

    usleep(RAND_INT(mem->atom_time));

    exit(EXIT_SUCCESS);
}

void main_process(mem_t *mem) {
    for (unsigned int i = 0; i < mem->o_count; i++) {
        pid_t oxygen_pid = fork();
        if (oxygen_pid < 0) {
            ERROR
        } else if (oxygen_pid == 0) {
            sub_process_oxygen(mem, i);
        }
    }

    for (long i = 0; i < mem->h_count; i++) {
        pid_t hydrogen_pid = fork();
        if (hydrogen_pid < 0) {
            ERROR
        } else if (hydrogen_pid == 0) {

        }
    }
}

process_t fork_process(unsigned int count, ATOM_TYPE type) {
    for (unsigned int i = 1; i <= count; i++) {
        if (fork() == 0)
            return (process_t) {.pid = getpid(), .atom = (atom_t) {.id = i, .type = type}};
    }

    return (process_t) {0};
}

