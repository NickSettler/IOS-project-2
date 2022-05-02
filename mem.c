#include <sys/ipc.h>
#include <sys/shm.h>
#include <printf.h>
#include <errno.h>
#include <string.h>
#include "mem.h"

mem_t *mem_init() {
    key_t key = ftok("main.c", 'c');

    int shmid = shmget(key, sizeof(mem_t), 0666 | IPC_CREAT);

    if (shmid == -1) ERROR

    mem_t *mem = shmat(shmid, NULL, 0);

    mem->mem_id = shmid;

    return mem;
}

void mem_fill(mem_t *mem) {
//    mem->line = 0;
//    mem->current_m = 0;
//    mem->m_id = 0;
//    mem->current_m_h = 0;
//    mem->current_h = 0;
//    mem->current_o = 0;
}

void mem_destroy(mem_t *mem) {
    key_t key = mem->mem_id;

    int control_result = shmctl(key, IPC_RMID, NULL);
    if (control_result == -1) ERROR

    shmdt(mem);
}
