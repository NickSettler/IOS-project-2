#include <stdlib.h>
#include "vector.h"

vector_t *vector_new(unsigned int capacity) {
    vector_t *v = malloc(sizeof(vector_t));
    v->capacity = capacity;
    v->size = 0;
    v->data = malloc(sizeof(void *) * capacity);
    return v;
}

void vector_push(vector_t *v, void *data) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, sizeof(void *) * v->capacity);
    }

    v->data[v->size++] = data;
}

void *vector_pop(vector_t *v) {
    if (v->size == 0) {
        return NULL;
    }

    void *data = v->data[--v->size];
    v->data[v->size] = NULL;

    return data;
}

void vector_unshift(vector_t *v, void *data) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, sizeof(void *) * v->capacity);
    }

    for (unsigned int i = v->size; i > 0; i--) {
        v->data[i] = v->data[i - 1];
    }

    v->data[0] = data;
    v->size++;
}

void *vector_shift(vector_t *v) {
    if (v->size == 0) {
        return NULL;
    }

    void *data = v->data[0];
    for (unsigned int i = 0; i < v->size - 1; i++) {
        v->data[i] = v->data[i + 1];
    }

    v->data[--v->size] = NULL;

    return data;
}

void vector_destroy(vector_t *v) {
    for (unsigned int i = 0; i < v->size; i++) {
        free(v->data[i]);
    }

    free(v->data);
    free(v);
}
