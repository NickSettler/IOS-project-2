#ifndef PROCESS_H
#define PROCESS_H

#include "main.h"

/**
 * Spawns a number of processes
 * @param count - number of processes to spawn
 * @param type - atom type corresponding to the processes
 * @return process_t structure
 */
process_t fork_process(unsigned int count, ATOM_TYPE type);

#endif //PROCESS_H
