#include "vector.h"
#include "assert.h"
#include <string.h>

/** Expands current array updating _alloced_count by _chunk_count
 *  Returns pointer to beginning on success, else NULL.
 */
void* _alloc_new_chunk(struct Vector* vector);

/** Retrieves starting address for last element in vector.
 *  Returns NULL on failure.
 */
void* _get_vector_end(struct Vector* vector);

int _get_element_idx(struct Vector* vector, void* start_addr);

void* _get_element_addr(struct Vector* vector, size_t idx);

int _shift_right(struct Vector* vector, size_t start_idx);

int _shift_left(struct Vector* vector, size_t start_idx);


// --------------------------------------------------------------------------------------------

struct Vector* vec_init(size_t _resize_count, size_t _element_size)
{
    ASSERT(_resize_count > 0, "Invalid resize_count parameter.\n");

    struct Vector* new = (struct Vector*)malloc(sizeof(struct Vector));

    if(new == NULL) return NULL;

    new->_element_size = _element_size;
    new->_resize_count = _resize_count;

    new->head = NULL;
    new->count = 0;
    new->_alloced_count = 0;

    _alloc_new_chunk(new);

    return new;
}

struct Vector* vec_init_default(size_t _element_size)
{
    return vec_init(DEFAULT_RESIZE_COUNT, _element_size);
}

int vec_insert(struct Vector* vector, void* data, size_t pos)
{
    ASSERT(pos <= vector->count, "Invalid insert operation.\n");
    ASSERT_NON_NULL_ARG(data, "data");

    if(vector->count == vector->_alloced_count)
        if (_alloc_new_chunk(vector) == NULL) return 1;

    void* ptr_to_pos = _get_element_addr(vector, pos);

    if(pos < vector->count)
        if(_shift_right(vector, pos) != 0) return 3;

    int memcpy_status = (memcpy(ptr_to_pos, data, vector->_element_size) == NULL);
    if(memcpy_status != 0) return 2;

    vector->count++;

    return 0;

}

int vec_append(struct Vector* vector, void* data)
{
    return vec_insert(vector, data, vector->count);
}

int vec_remove(struct Vector* vector, size_t pos)
{
    ASSERT_NON_NULL_ARG(vector, "vector");
    ASSERT(pos < vector->count, "Invalid value of argument 'pos'.\n");

   if(pos < (vector->count - 1))
   {
       int shift_status = _shift_left(vector, pos);
       if(shift_status != 0) return 1;
   }

   vector->count--;

   return 0;
}

void* vec_at(struct Vector* vector, size_t pos)
{
    return _get_element_addr(vector, pos);
}

void* _alloc_new_chunk(struct Vector* vector)
{
    ASSERT(vector != NULL, "NULL argument passed.\n");

    size_t new_alloced_count = vector->_alloced_count + vector->_resize_count;
    size_t element_size = vector->_element_size;
    size_t op_size = new_alloced_count * element_size;

    if(vector->head == NULL)
        vector->head = malloc(op_size);
    else
        vector->head = realloc(vector->head, op_size);

    if(vector->head == NULL) return NULL;

    vector->_alloced_count = new_alloced_count;
    return vector->head;
}

int _shift_right(struct Vector* vector, size_t start_idx)
{
    ASSERT(start_idx < vector->count, "Invalid start_idx parameter.\n");
    ASSERT_NON_NULL_ARG(vector, 'vector');

    size_t vector_count = vector->count;

    ASSERT(vector_count < vector->_alloced_count, "_shift_right called when count == _alloced_count.\n");

    size_t step = vector->_element_size;
    size_t elements_shifted = vector_count - start_idx;

    // 10 | 15 | 55 | 

    void* start_pos = _get_element_addr(vector, start_idx);

    int memmove_status = (memmove(start_pos + step, start_pos, step * elements_shifted) == NULL);
    return memmove_status;
}

int _shift_left(struct Vector* vector, size_t start_idx)
{
    ASSERT_NON_NULL_ARG(vector, 'vector');

    void* vector_end = _get_vector_end(vector);
    size_t vector_count = vector->count;

    ASSERT(start_idx < vector_count, "Invalid argument 'start_idx' passed.\n");
    ASSERT(vector_count < vector->_alloced_count, "_shift_right called when count == _alloced_count.\n");

    size_t step = vector->_element_size;
    size_t elements_shifted = vector_count - start_idx - 1;

    void* start_pos = _get_element_addr(vector, start_idx);

    return (memmove(start_pos, start_pos + step, step * elements_shifted) == NULL);
}

void* _get_vector_end(struct Vector* vector)
{
    ASSERT_NON_NULL_ARG(vector, "vector");
    ASSERT(vector->head != NULL, "Argument 'vector' must have 'head' as non-null.\n");

    return vector->head + ((vector->count - 1) * vector->_element_size);
}

int _get_element_idx(struct Vector* vector, void* start_addr)
{
    void* vector_head = vector->head;
    ASSERT_NON_NULL_ARG(vector, "vector");
    ASSERT(((start_addr >= vector_head) && (start_addr <= _get_vector_end(vector))), "Invalid value of 'start_addr' argument.\n");

    return (vector_head - start_addr) / vector->_element_size;
}

void* _get_element_addr(struct Vector* vector, size_t idx)
{
    void* vector_head = vector->head;
    ASSERT_NON_NULL_ARG(vector, "vector");
    ASSERT(idx <= vector->count, "Invalid value of argument 'idx'\n.");

    return vector->head + (idx * vector->_element_size);
}
