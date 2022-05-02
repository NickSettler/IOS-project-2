#include <stdlib.h>
#include <printf.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "process.h"
#include "helpers.h"

void sub_process_oxygen(mem_t *mem, unsigned int atom_id) {
    sem_wait(mem->semaphores->output_sem);
    atom_t *atom = NULL;
    for (unsigned int i = 0; i < mem->o_count; i++) {
        atom_t *loop_atom = mem->o_vector->data[i];

        if (loop_atom->id == atom_id) {
            atom = loop_atom;
            break;
        }
    }

    if(atom == NULL)
        print_error("Could not find atom with id %d\n", atom_id);

    mem->line++;
    printf("%d: %c %d: started\n", mem->line, atom->type, atom->id);
    sem_post(mem->semaphores->output_sem);

    usleep(RAND_INT(mem->atom_time));

    exit(0);
}

void main_process(mem_t *mem) {
    for (int i = 0; i < mem->o_count; i++) {
        pid_t oxygen_pid = fork();
        if (oxygen_pid < 0) {
            print_error("Oxygen process creation failed\n"
                        "%s:%d %s\n", __FILE__, __LINE__, strerror(errno));
        } else if (oxygen_pid == 0) {
            sub_process_oxygen(mem, i);
        }
    }

    for (long i = 0; i < mem->h_count; i++) {
        pid_t hydrogen_pid = fork();
        if (hydrogen_pid < 0) {
            print_error("Hydrogen process creation failed\n"
                        "%s:%d %s\n", __FILE__, __LINE__, strerror(errno));
        } else if (hydrogen_pid == 0) {

        }
    }
}

