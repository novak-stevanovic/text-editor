#ifndef _VECTOR_H
#define _VECTOR_H

#include <stdlib.h>

#define DEFAULT_RESIZE_COUNT 100

struct Vector
{
    size_t count; // current count of elements
    size_t _alloced_count; // current array capacity
    size_t _resize_count; // how much the array resizes on realloac
    size_t _element_size; // size of 1 element
    void* head; // ptr to array
};

/* Allocates memory for struct Vector <vector>, initializes struct fields. Allocates the memory for the first <_initial_count> elements of the array. 
 * Return value:
 * on success: 0
 * on failure: 1 - allocing first chunk for array failed */
int vec_init(struct Vector* vector, size_t _initial_count, size_t _resize_count, size_t _element_size);

/* Calls vec_init with parameter <_resize_count> set to DEFAULT_RESIZE_COUNT. 
 * Return value:
 * on success: 0
 * on failure: 1 - allocing first chunk for array failed */
int vec_init_default(struct Vector* vector, size_t _initial_count, size_t _element_size);

/* Inserts element pointed at by <data> at index <pos> in the Vector <vector>. May result in resizing of <vector>.
 * Return value:
 * on success: 0
 * on failure:
 * 1 - array had to be resized and the operation failed.
 * 2 - failure to perform memcpy() for calculated dest address and <data> src address.
 * 3 - failure to shift elements starting from index <pos> rightward. */
int vec_insert(struct Vector* vector, void* data, size_t pos);

/* Appends data pointed at by <data> at the end of the Vector <vector>. Calls vec_insert() by specyfing <pos> as <vector>->count - 1.
 * May result in resizing of <vector>.
 * Return value:
 * on success: 0
 * on failure:
 * 1 - array had to be resized and the operation failed.
 * 2 - failure to perform memcpy() for calculated dest address and <data> src address. */
int vec_append(struct Vector* vector, void* data);

/* Removes element at index <pos> in Vector <vector>. May result in resizing of <vector>.
 * Return value:
 * on success: 0
 * on failure:
 * 1 - failure to shift elements starting from index <pos + 1> leftward.
 * 2 - failure to resize Vector <vector>. */
int vec_remove(struct Vector* vector, size_t pos);

/* Calculates address of element with index specified by <pos>.
 * Return value:
 * Address of element with index <pos>. */
void* vec_at(struct Vector* vector, size_t pos);

/* Assigns data <data> to element in array with index <pos>. Replaces assignment operator '=' */
void vec_assign_by_pos(struct Vector* vector, size_t pos, void* data);

/* Frees dynamically allocated memory */
void vec_destruct(struct Vector* vector);

#endif
