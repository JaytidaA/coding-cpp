/*
 * vector.c
 * Implements a simple vector in C
 * Author: https://github.com/JaytidaA
 */

#include <stdlib.h>
#include <stdbool.h>
#include "err_handle.h"
#include "vector.h"

/* internal helpers */
void vmem_reallocation(Vector *v);
size_t vnew_cap(size_t cap);

/******************************************************************************
 * new_vector: Creates and initialses a new empty vector with space for       *
 *             INITIAL_VEC_CAP element(s). Exits the program on failure to    *
 *             allocate enough memory.                                        *
 ******************************************************************************/
Vector *new_vector(void)
{
	Vector *temp = (Vector *) malloc(sizeof(Vector));
	if (!temp)
		ERR_NULL_MALLOC(1, __func__);

	temp->size = 0;
	temp->capacity = INITIAL_VEC_CAP;
	temp->arr = (Item *) malloc(temp.capacity * sizeof(Item));
	if (!(temp->arr))
		ERR_NULL_MALLOC(INITIAL_VEC_CAP, __func__);

	return temp;
}

/******************************************************************************
 * new_vector_cap: Creates and initialises a new empty vector with space for  *
 *                 'n' elements. Exits the program on failure to allocate     *
 *                 enough memory.                                             *
 ******************************************************************************/
Vector *new_vector_cap(size_t n)
{
	Vector *temp = (Vector *) malloc(sizeof(Vector));
	if (!temp)
		ERR_NULL_MALLOC(1, __func__);

	temp->size = 0;
	temp->capacity = (!n) ? INITIAL_VEC_CAP : n;
	temp->arr = (Item *) malloc(temp.capacity * sizeof(Item));
	if (!(temp->arr))
		ERR_NULL_MALLOC(n, __func__);

	return temp;
}

/******************************************************************************
 * new_vector_fill: Creates and initialises a vector with space for 'n'       *
 *                  elements and initialises them with value 'i'. Exits the   *
 *                  program on failure to allocate enough memory.             *
 ******************************************************************************/
Vector *new_vector_fill(size_t n, Item i)
{
	if (!n)
		return NULL;

	Vector *temp = (Vector *) malloc(sizeof(Vector));
	if (!temp)
		ERR_NULL_MALLOC(1, __func__);

	temp->size = n;
	temp->capacity = n;
	temp->arr = (Item *) malloc(temp.capacity * sizeof(Item));
	if (!(temp->arr))
		ERR_NULL_MALLOC(n, __func__);
	
	for (int j = 0; j < n; j++)
		temp->arr[j] = i;

	return temp;
}

Vector *reset_vector(Vector *v)
{
	free(v->arr);
	v->size = v->capacity = 0;
	return v;
}

void delete_vector(Vector *v)
{
	free(reset_vector(v));
}

/* popular functions */
void push_back(Vector *v, Item i)
{
	if (v->size == v->capacity)
		vmem_reallocation(v);
	v->arr[(v->size)++] = i;
}

void pop_back(Vector *v)
{
	if (!empty(v))
		v->size -= 1;
}

Item *front(const Vector *v)
{
	return empty(v) ? NULL : v->arr[0];
}

Item *back(const Vector *v)
{
	return empty(v) ? NULL : v->arr[v->size - 1];
}

size_t size(const Vector *v)
{
	return v->size;
}

size_t capacity(const Vector *v)
{
	return v->capacity;
}

Item *at_ptr(const Vector *v, size_t i)
{
	return (i >= v->size) ? NULL : v->arr[i];
}

bool empty(const Vector *v)
{
	return (v->size == 0);
}

void clear(Vector *v)
{
	v->size = 0;
}

void vmem_reallocation(Vector *v)
{
	size_t new_cap = vnew_cap(v->capacity);
	Item *temp = (Item *) malloc(new_cap * sizeof(Item));
	if (!temp)
		ERR_NULL_MALLOC(new_cap, __func__);

	for (int i = 0; i < v->size; i++)
		temp[i] = v->arr[i];
	free(v->arr);
	v->arr = temp;
}

size_t vnew_cap(size_t cap)
{
#if defined(LINEAR_ALLOC)
	return cap + ALLOC_CONST;
#elif defined(EXP_ALLOC)
	return cap * ALLOC_CONST;
#endif
}
