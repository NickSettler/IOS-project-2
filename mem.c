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

    if (shmid == -1) ERROR

    void *mem_addr = shmat(shmid, NULL, 0);

    if (mem_addr == (void *) -1) ERROR

    mem->mem_id = shmid;
    mem->mem_addr = mem_addr;

    return mem;
}

void mem_fill(mem_t *mem, int NO, int NH, int TI, int TB) {
    mem->line = 0;
    mem->o_count = NO;
    mem->h_count = NH;
    mem->current_m = 0;
    mem->m_id = 0;
    mem->current_m_h = 0;
    mem->atom_time = TI;
    mem->molecule_time = TB;
    mem->current_h = 0;
    mem->current_o = 0;
    mem->output_file = open_output();
}

void mem_destroy(mem_t *mem) {
    close_output(mem->output_file);

    int unmap_result = shmdt(mem->mem_addr);
    if (unmap_result == -1) ERROR

    int control_result = shmctl(mem->mem_id, IPC_RMID, NULL);
    if (control_result == -1) ERROR
    free(mem);
}
