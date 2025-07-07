/*
 * utils.c
 * Defines utility functions and MACROS for the Data Structures defined in the
 * repository https://github.com/JaytidaA/coding-cpp
 * Author: https://github.com/JaytidaA/
 */

#include "utils.h"

#ifdef __STDC_HOSTED__
#define IS_PRINTABLE
#include <stdio.h>
#endif

void print_vector(Vector *v)
{
#ifdef IS_PRINTABLE
	putchar('<');
	if (empty(v)) {
		puts(" >");
		return;
	}
	for (int i = 0; i < size(v) - 1; i++)
		printf("%d, ", *at_ptr(v, i));
	printf("%d>\n", *back(v));
#endif
}
