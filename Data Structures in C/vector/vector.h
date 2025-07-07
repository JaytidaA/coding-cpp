/*
 * vector.h
 * Implements a simple vector in C
 * Author: https://github.com/JaytidaA/
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_VEC_CAP 1
#define LINEAR_ALLOC

#if defined(EXP_ALLOC)
#undef LINEAR_ALLOC
#endif

#if defined(LINEAR_ALLOC)
#define ALLOC_CONST 5
#elif defined(EXP_ALLOC)
#define ALLOC_CONST 1.5
#endif

typedef int Item;

typedef struct {
    Item *arr;
    size_t size;
    size_t capacity;
} Vector;

/* prototypes */
Vector *new_vector(void);
Vector *new_vector_cap(size_t n);
Vector *new_vector_fill(size_t n, Item i);
Vector *reset_vector(Vector *);
void delete_vector(Vector *);

void push_back(Vector *v, Item i);
void pop_back(Vector *v);
Item *front(const Vector *v);
Item *back(const Vector *v);

size_t size(const Vector *v);
size_t capacity(const Vector *v);

Item *at_ptr(const Vector *v, size_t i);

bool empty(const Vector *v);
void clear(Vector *v);

#endif
