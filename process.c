#include <unistd.h>
#include "process.h"

process_t fork_process(unsigned int count, ATOM_TYPE type) {
    for (unsigned int i = 1; i <= count; i++) {
        if (fork() == 0)
            return (process_t) {.atom = (atom_t) {.id = i, .type = type}};
    }

    return (process_t) {0};
}

