#ifndef VECTOR_H
#define VECTOR_H

/**
 * @struct vector_t
 * Vector of pointers to void
 *
 * @var vector_t::size
 * Size of the vector
 *
 * @var vector_t::capacity
 * Capacity of the vector
 *
 * @var vector_t::data
 * Pointers to the data
 */
typedef struct vector_t {
    /* Size of the vector */
    unsigned int size;
    /* Capacity of the vector */
    unsigned int capacity;
    /* Pointers to the data */
    void **data;
} vector_t;

/**
 * Initialize vector_t.
 * @param capacity - initial capacity of vector_t.
 * @return - pointer to vector_t.
 */
vector_t *vector_new(unsigned int capacity);

/**
 * Push element to the end of vector_t.
 * @param v - vector_t.
 * @param data - data to be pushed.
 */
void vector_push(vector_t *v, void *data);


/**
 * Pop element from the end of vector_t.
 * @param v - vector_t.
 * @return - data from the end of vector_t.
 */
void *vector_pop(vector_t *v);

/**
 * Add element to the head of vector_t.
 * @param v - vector_t.
 * @param data - data to be added.
 */
void vector_unshift(vector_t *v, void *data);

/**
 * Remove element from the head of vector_t.
 * @param v - vector_t.
 * @return - data from the head of vector_t.
 */
void *vector_shift(vector_t *v);

/**
 * Free vector_t.
 * @param v - vector_t to free.
 */
void vector_destroy(vector_t *v);

#endif //VECTOR_H
