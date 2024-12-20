#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

#define DEFAULT_RESIZE_COUNT 100

struct Vector
{
    size_t count;
    size_t _alloced_count;
    size_t _resize_count;
    size_t _element_size;
    void* head;
};

struct Vector* vec_init_default(size_t _element_size);

struct Vector* vec_init(size_t _resize_count, size_t _element_size);

/** Inserts element at pos parameter.
 *  Returns 1 if alloc/realloc failed, 2 if memcpy failed. 0 on success.
 */
int vec_insert(struct Vector*, void* data, size_t pos);

int vec_append(struct Vector*, void* data);

int vec_remove(struct Vector*, size_t pos);

void* vec_at(struct Vector* vector, size_t pos);

#endif
