#include <unistd.h>
#include "helpers.h"
#include "mem.h"
#include "process.h"

int main(int argc, char **argv) {
    remove_output();

    args_t args;
    parse_args(&args, argc, argv);

    semaphores_t semaphores;
    semaphores_init(&semaphores);
    mem_t *mem = mem_init();

    process_t process;
    pid_t main_id = getpid();

    if (args.EH == 0 && args.EO == 0) {
        sem_post(semaphores.stop_extra_sem);
    }

    if (main_id == getpid()) {
        process = fork_process(args.NO, OXYGEN);
    }

    if (main_id == getpid()) {
        process = fork_process(args.NH, HYDROGEN);
    }

    if (main_id != getpid()) {
        sem_wait(semaphores.output_sem);

        output_to_file(mem, ATOM_CREATED, &process);

        sem_post(semaphores.output_sem);

        usleep(RAND_INT(args.TI));

        sem_wait(semaphores.output_sem);

        output_to_file(mem, ATOM_TO_QUEUE, &process);

        sem_post(semaphores.output_sem);

        switch (process.atom.type) {
            case HYDROGEN:
                mem->current_h++;
                process.extra_info = args.EH < mem->current_h;
                break;
            case OXYGEN:
                mem->current_o++;
                process.extra_info = args.EO < mem->current_o;
                break;
        }

        if (process.extra_info) {
            sem_wait(semaphores.stop_extra_sem);
            output_to_file(mem, process.atom.type == OXYGEN ? ATOM_INSUFFICIENT_O : ATOM_INSUFFICIENT_H, &process);
            sem_post(semaphores.stop_extra_sem);
            exit(EXIT_SUCCESS);
        }

        if (process.atom.type == HYDROGEN) {
            sem_wait(semaphores.h_sem);
            sem_wait(semaphores.output_sem);
            output_to_file(mem, ATOM_FROM_QUEUE, &process);
            sem_post(semaphores.output_sem);

            if (++mem->current_m_h >= 2) {
                sem_post(semaphores.creating_sem);
                sem_post(semaphores.creating_sem);
                sem_post(semaphores.creating_sem);
            }

            sem_wait(semaphores.creating_sem);

            usleep(RAND_INT(args.TB));

            sem_wait(semaphores.output_sem);

            output_to_file(mem, ATOM_READY, &process);

            sem_post(semaphores.output_sem);

            --mem->current_m_h;

            sem_post(semaphores.ready_sem);

            exit(EXIT_SUCCESS);
        } else if (process.atom.type == OXYGEN) {
            sem_wait(semaphores.o_sem);

            ++mem->m_id;

            sem_wait(semaphores.output_sem);

            output_to_file(mem, ATOM_FROM_QUEUE, &process);

            sem_post(semaphores.output_sem);
            sem_post(semaphores.h_sem);
            sem_post(semaphores.h_sem);

            sem_wait(semaphores.creating_sem);

            usleep(RAND_INT(args.TB));

            sem_wait(semaphores.output_sem);

            output_to_file(mem, ATOM_READY, &process);

            sem_post(semaphores.output_sem);

            sem_wait(semaphores.ready_sem);
            sem_wait(semaphores.ready_sem);

            if (args.EO == mem->m_id) {
                sem_post(semaphores.stop_extra_sem);
            }

            sem_post(semaphores.o_sem);

            exit(EXIT_SUCCESS);
        }
    }

    semaphores_destroy(&semaphores);

    mem_destroy(mem);

    return EXIT_SUCCESS;
}
