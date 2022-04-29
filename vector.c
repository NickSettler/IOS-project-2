#include <stdlib.h>
#include "vector.h"

vector *vector_new(int capacity) {
    vector *v = malloc(sizeof(vector));
    v->capacity = capacity;
    v->size = 0;
    v->data = malloc(sizeof(void *) * capacity);
    return v;
}

void vector_destroy(vector *v) {
    free(v->data);
    free(v);
}
