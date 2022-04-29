#ifndef VECTOR_H
#define VECTOR_H

// create vector type with specified size
typedef struct {
    int size;
    int capacity;
    int *data;
} vector;

/**
 * Initialize vector.
 * @param capacity - initial capacity of vector.
 * @return
 */
vector *vector_new(int capacity);

/**
 * Free vector.
 * @param v - vector to free.
 */
void vector_destroy(vector *v);

#endif //VECTOR_H
