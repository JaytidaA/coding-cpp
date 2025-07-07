/*
 * general.c
 * Example to show off the various properties of Vector.
 * Author: https://github.com/JaytidaA/
 */

#include "vector/vector.h"
#include "vector/vector_utils.h"
#include <stdio.h>

int main(void)
{
	Vector *v = new_vector();
	printf("Vector at time T1: "); print_vector(v);
	push_back(v, 1);
	push_back(v, 2);
	push_back(v, 3);
	push_back(v, 4);
	push_back(v, 5);
	printf("Vector at time T2: "); print_vector(v);
	pop_back(v);
	printf("Vector at time T3: "); print_vector(v);
	printf("Size of vector at T3: %zu\n", size(v));
	printf("First element of the vector: %d\n", *front(v));
	printf("Clearing the vector...");
	clear(v);
	printf("Vector at time T4: "); print_vector(v);
	delete_vector(v);
	return 0;
}
