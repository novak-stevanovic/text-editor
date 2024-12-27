#include "vector.h"
#include "assert.h"
#include <string.h>

/* Resizes Vector <vector> by performing alloc/realloc. Call to this function extends memory by _resize_count * <vector>->_element_size.
 * Return value:
 * on success: address of <vector>->head
 * on failure: NULL. */
void* _alloc_new_chunk(struct Vector* vector, size_t _resize_count);

/* Calls _alloc_new_chunk() with parameters (<vector>, <vector>->_resize_count).
 * Return value: Same as _alloc_new_chunk(). */
void* _alloc_new_chunk_rsz(struct Vector* vector);

/* Calculates <vector>'s tail.
 * Return value: Pointer to address of last element in Vector <vector>. */
void* _get_vector_tail(struct Vector* vector);

/* Calculates position of element with starting address <start_addr> in Vector <vector>.
 * Return value: Index of calculated position. */
size_t _get_element_idx(struct Vector* vector, void* start_addr);

/* Calculates starting address of element with index <idx> in Vector <vector>.
 * Return value: Pointer to calculated starting address. */
void* _get_element_addr(struct Vector* vector, size_t idx);

/* Shift elements starting from index <start_idx> rightward by calling memmove().
 * Return value:
 * on success: 0
 * on failure: 1 - memmove() failed. */
int _shift_right(struct Vector* vector, size_t start_idx);

/* Shift elements starting from index <start_idx> leftward by calling memmove().
 * Return value:
 * on success: 0
 * on failure: 1 - memmove() failed. */
int _shift_left(struct Vector* vector, size_t start_idx);

void __print_int_vector_debug(struct Vector* v);

// --------------------------------------------------------------------------------------------

int vec_init(struct Vector* vector, size_t _initial_count, size_t _resize_count, size_t _element_size)
{
    ASSERT_NON_NULL_ARG(vector, 'vector');
    ASSERT(_initial_count != 0, "Invalid '_initial_count' parameter");
    ASSERT(_resize_count != 0, "Invalid '_resize_count' parameter");
    ASSERT(_element_size != 0, "Invalid '_element_size' parameter");

    vector->_element_size = _element_size;
    vector->_resize_count = _resize_count;

    vector->head = NULL;
    vector->count = 0;
    vector->_alloced_count = 0;

    if (_alloc_new_chunk(vector, _initial_count) == NULL) return 1;

    return 0;
}

int vec_init_default(struct Vector* vector, size_t _initial_count, size_t _element_size)
{
    return vec_init(vector, _initial_count, DEFAULT_RESIZE_COUNT, _element_size);
}

int vec_insert(struct Vector* vector, void* data, size_t pos)
{
    ASSERT(pos <= vector->count, "Invalid insert operation.\n");
    ASSERT_NON_NULL_ARG(data, "data");

    if(vector->count == vector->_alloced_count)
        if (_alloc_new_chunk_rsz(vector) == NULL) return 1;

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
       int shift_status = _shift_left(vector, pos + 1);
       if(shift_status != 0) return 1;
   }

   vector->count--;

   size_t count = vector->count;
   size_t alloced_count = vector->_alloced_count;
   size_t resize_count = vector->_resize_count;
   size_t element_size = vector->_element_size;


   int chunks_required = count % resize_count + (resize_count - (count % resize_count));
   int chunks_alloced = alloced_count / resize_count;

   if(chunks_required < chunks_alloced)
   {
       vector->head = realloc(vector->head, chunks_required * resize_count * element_size);
       vector->_alloced_count -= chunks_required * resize_count;
   }

   if(vector->head == NULL) return 2;

   return 0;
}

void* vec_at(struct Vector* vector, size_t pos)
{
    return _get_element_addr(vector, pos);
}

void* _alloc_new_chunk(struct Vector* vector, size_t _resize_count)
{
    ASSERT_NON_NULL_ARG(vector, "vector");

    size_t new_alloced_count = vector->_alloced_count + _resize_count;
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

void* _alloc_new_chunk_rsz(struct Vector* vector)
{
    ASSERT_NON_NULL_ARG(vector, "vector");
    return _alloc_new_chunk(vector, vector->_resize_count);
}

void* _get_vector_tail(struct Vector* vector)
{
    ASSERT_NON_NULL_ARG(vector, "vector");
    ASSERT(vector->head != NULL, "Argument 'vector' must have 'head' as non-null.\n");

    return (vector->count == 0 ? NULL : vector->head + ((vector->count - 1) * vector->_element_size));
}

size_t _get_element_idx(struct Vector* vector, void* start_addr)
{
    void* vector_head = vector->head;
    ASSERT_NON_NULL_ARG(vector, "vector");
    ASSERT(((start_addr >= vector_head) && (start_addr <= _get_vector_tail(vector))), "Invalid value of 'start_addr' argument.\n");

    return ((size_t)(start_addr - vector_head)) / vector->_element_size;
}

void* _get_element_addr(struct Vector* vector, size_t idx)
{
    void* vector_head = vector->head;
    ASSERT_NON_NULL_ARG(vector, "vector");
    ASSERT(idx <= vector->count, "Invalid value of argument 'idx'\n.");

    return vector->head + (idx * vector->_element_size);
}

int _shift_right(struct Vector* vector, size_t start_idx)
{
    ASSERT(start_idx < vector->count, "Invalid start_idx parameter.\n");
    ASSERT_NON_NULL_ARG(vector, 'vector');

    size_t vector_count = vector->count;

    ASSERT(vector_count < vector->_alloced_count, "_shift_right called when count == _alloced_count.\n");

    size_t step = vector->_element_size;
    size_t elements_shifted = vector_count - start_idx;

    void* start_pos = _get_element_addr(vector, start_idx);

    int memmove_status = (memmove(start_pos + step, start_pos, step * elements_shifted) == NULL);
    return memmove_status;
}

int _shift_left(struct Vector* vector, size_t start_idx)
{
    ASSERT_NON_NULL_ARG(vector, "vector");

    void* vector_tail = _get_vector_tail(vector);
    size_t vector_count = vector->count;

    ASSERT(start_idx < vector_count, "Invalid argument 'start_idx' passed.\n");

    size_t step = vector->_element_size;
    size_t elements_shifted = vector_count - start_idx;

    void* start_pos = _get_element_addr(vector, start_idx) - step;

    return (memmove(start_pos, start_pos + step, step * elements_shifted) == NULL);
}

void __print_int_vector_debug(struct Vector* v)
{
    printf("vector tail: %p, count: %ld, alloced_count: %ld, resize_count: %ld, vector_head: %p\n", _get_vector_tail(v), v->count, v->_alloced_count, v->_resize_count, v->head);

    for (size_t i = 0; i < v->count; i++) {
        void* el_addr = vec_at(v, i);
        size_t el_idx = _get_element_idx(v, el_addr);
        int el_val = *((int*)el_addr);
        void* el_addr2 = _get_element_addr(v, i);
        printf("addr: %p ret_idx: %ld val: %d ret_addr:%p i: %ld\n", el_addr, el_idx, el_val, el_addr2, i);
    }
    putchar('\n');
}
