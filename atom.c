#include <stdlib.h>
#include "atom.h"

atom_t *atom_create(unsigned int id, ATOM_TYPE type) {
    atom_t *atom = malloc(sizeof(atom_t));
    atom->id = id;
    atom->type = type;
    return atom;
}

atom_t *atom_copy(atom_t *dest, atom_t *src) {
    dest->id = src->id;
    dest->type = src->type;
    return dest;
}

void atom_destroy(atom_t *atom) {
    free(atom);
}

