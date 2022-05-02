#include <unistd.h>
#include "helpers.h"
#include "mem.h"
#include "process.h"

int main(int argc, char **argv) {
    args_t *args = parse_args(argc, argv);

    mem_t *mem = mem_init();
    mem_fill(mem, args->NO, args->NH, args->TI, args->TB);

    process_t process;
    pid_t main_id = getpid();

    if (args->EH == 0 && args->EO == 0) {
        sem_post(mem->semaphores->stop_extra_sem);
    }

    if (main_id == getpid()) {
        process = fork_process(args->NO, OXYGEN);
    }

    if (main_id == getpid()) {
        process = fork_process(args->NH, HYDROGEN);
    }

    if (main_id != getpid()) {
        sem_wait(mem->semaphores->output_sem);

        output_to_file(mem, ATOM_CREATED, &process);

        sem_post(mem->semaphores->output_sem);

        usleep(RAND_INT(args->TI));

        sem_wait(mem->semaphores->output_sem);

        output_to_file(mem, ATOM_TO_QUEUE, &process);

        sem_post(mem->semaphores->output_sem);

        switch (process.atom.type) {
            case HYDROGEN:
                mem->current_h++;
                process.extra_info = args->EH < mem->current_h;
                break;
            case OXYGEN:
                mem->current_o++;
                process.extra_info = args->EO < mem->current_o;
                break;
        }

        if (process.extra_info) {
            sem_wait(mem->semaphores->stop_extra_sem);
            output_to_file(mem, process.atom.type == OXYGEN ? ATOM_INSUFFICIENT_O : ATOM_INSUFFICIENT_H, &process);
            sem_post(mem->semaphores->stop_extra_sem);
            exit(EXIT_SUCCESS);
        }

        if (process.atom.type == HYDROGEN) {
            sem_wait(mem->semaphores->h_sem);
            sem_wait(mem->semaphores->output_sem);
            output_to_file(mem, ATOM_FROM_QUEUE, &process);
            sem_post(mem->semaphores->output_sem);

            if (++mem->current_m >= 2) {
                sem_post(mem->semaphores->creating_sem);
                sem_post(mem->semaphores->creating_sem);
                sem_post(mem->semaphores->creating_sem);
            }

            sem_wait(mem->semaphores->creating_sem);

            usleep(RAND_INT(args->TB));

            sem_wait(mem->semaphores->output_sem);

            output_to_file(mem, ATOM_READY, &process);

            sem_post(mem->semaphores->output_sem);

            --mem->current_m_h;

            sem_post(mem->semaphores->ready_sem);

            exit(EXIT_SUCCESS);
        } else if (process.atom.type == OXYGEN) {
            sem_wait(mem->semaphores->o_sem);

            ++mem->m_id;

            sem_wait(mem->semaphores->output_sem);

            output_to_file(mem, ATOM_FROM_QUEUE, &process);

            sem_post(mem->semaphores->output_sem);
            sem_post(mem->semaphores->h_sem);
            sem_post(mem->semaphores->h_sem);

            sem_wait(mem->semaphores->creating_sem);

            usleep(RAND_INT(args->TB));

            sem_wait(mem->semaphores->output_sem);

            output_to_file(mem, ATOM_READY, &process);

            sem_post(mem->semaphores->output_sem);

            sem_wait(mem->semaphores->ready_sem);
            sem_wait(mem->semaphores->ready_sem);

            if (args->EO == mem->m_id) {
                sem_post(mem->semaphores->stop_extra_sem);
            }

            sem_post(mem->semaphores->o_sem);

            exit(EXIT_SUCCESS);
        }

        exit(EXIT_SUCCESS);
    }

    mem_destroy(mem);
}
