#include <sys/ipc.h>
#include <sys/shm.h>
#include <printf.h>
#include <stdlib.h>
#include <errno.h>
#include "mem.h"

mem_t *mem_init() {
    mem_t *mem = malloc(sizeof(mem_t));

    key_t key = ftok("xmoise01/shm", 65);

    int shmid = shmget(key, sizeof(mem_t), 0666 | IPC_CREAT);

    if (errno == -1) {
        perror("shmget");
        exit(1);
    }

    void *mem_addr = shmat(shmid, NULL, 0);

    if (errno == -1) {
        perror("shmat");
        exit(1);
    }

    mem->mem_id = shmid;
    mem->mem_addr = mem_addr;

    return mem;
}


void mem_fill(mem_t *mem, int NO, int NH, int TI, int TB) {
    mem->line = 1;
    mem->o_count = NO;
    mem->h_count = NH;
    mem->m_count = 0;
    mem->atom_time = TI;
    mem->molecule_time = TB;
    mem->current_h = 0;
    mem->current_o = 0;
}

void mem_destroy(mem_t *mem) {
    printf("%d\n", mem->line);
    shmdt(mem->mem_addr);
    shmctl(mem->mem_id, IPC_RMID, NULL);
    free(mem);
}
