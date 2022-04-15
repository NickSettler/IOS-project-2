#include <stdio.h>
#include <stdlib.h>

unsigned long O_NUMBER = 0;
unsigned long H_NUMBER = 0;
unsigned long ATOM_TIME = 0;
unsigned long MOLECULE_TIME = 0;

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s NO NH TI TB\n", argv[0]);
        exit(1);
    }

    O_NUMBER = strtol(argv[1], NULL, 10);
    H_NUMBER = strtol(argv[2], NULL, 10);
    ATOM_TIME = strtol(argv[3], NULL, 10);
    MOLECULE_TIME = strtol(argv[4], NULL, 10);

    if (O_NUMBER < 0 || H_NUMBER < 0 || ATOM_TIME < 0 || MOLECULE_TIME < 0) {
        fprintf(stderr, "Usage: %s NO NH TI TB\n", argv[0]);
        exit(1);
    }

    if (ATOM_TIME > 1000 || MOLECULE_TIME > 1000) {
        fprintf(stderr, "Usage: %s NO NH TI TB\n", argv[0]);
        exit(1);
    }

    printf("Arguments number: %d\n", argc);
    printf("O_NUMBER = %lu\n", O_NUMBER);
}
