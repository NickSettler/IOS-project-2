#ifndef ATOM_H
#define ATOM_H

#include "helpers.h"

typedef enum ATOM_TYPE {
    OXYGEN = 'O',
    HYDROGEN = 'H',
} ATOM_TYPE;

typedef struct atom_t {
    unsigned int id;
    ATOM_TYPE type;
    bool ready;
} atom_t;

atom_t* atom_create(unsigned int id, ATOM_TYPE type);

atom_t* atom_copy(atom_t *dest, atom_t *src);

void atom_destroy(atom_t *atom);

#endif //ATOM_H
