#include <sys/ipc.h>
#include <sys/shm.h>
#include <printf.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "mem.h"
#include "atom.h"

mem_t *mem_init() {
    mem_t *mem = malloc(sizeof(mem_t));

    key_t key = ftok("xmoise01/shm", 65);

    int shmid = shmget(key, sizeof(mem_t), 0666 | IPC_CREAT);

    if (shmid == -1)
        print_error("%s:%d %s\n", __FILE__, __LINE__, strerror(errno));

    void *mem_addr = shmat(shmid, NULL, 0);

    if (mem_addr == (void *) -1)
        print_error("%s:%d %s\n", __FILE__, __LINE__, strerror(errno));

    mem->mem_id = shmid;
    mem->mem_addr = mem_addr;

    return mem;
}

void mem_fill(mem_t *mem, int NO, int NH, int TI, int TB) {
    mem->line = 1;
    mem->o_count = NO;
    mem->h_count = NH;
    mem->current_m = 1;
    mem->atom_time = TI;
    mem->molecule_time = TB;
    mem->current_h = 0;
    mem->current_o = 0;
    mem->o_vector = vector_new(NO);
    mem->h_vector = vector_new(NH);

    for (unsigned int i = 0; i < mem->o_vector->capacity; i++) {
        atom_t *atom = atom_create(i, OXYGEN);
        vector_push(mem->o_vector, atom);
    }

    for (unsigned int i = 0; i < mem->h_vector->capacity; i++) {
        atom_t *atom = atom_create(i, HYDROGEN);
        vector_push(mem->h_vector, atom);
    }
}

void mem_destroy(mem_t *mem) {
    vector_destroy(mem->o_vector);
    vector_destroy(mem->h_vector);
    shmdt(mem->mem_addr);
    shmctl(mem->mem_id, IPC_RMID, NULL);
    free(mem);
}
