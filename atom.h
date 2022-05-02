#ifndef ATOM_H
#define ATOM_H

#include <stdbool.h>
#include "helpers.h"

atom_t* atom_create(unsigned int id, ATOM_TYPE type);

atom_t* atom_copy(atom_t *dest, atom_t *src);

void atom_destroy(atom_t *atom);

#endif //ATOM_H
