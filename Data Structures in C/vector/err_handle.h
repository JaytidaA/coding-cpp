/*
 * err_handle.h
 * Basic error handling functions and macros
 * Author: https://github.com/JaytidaA/
 */

#ifndef ERR_HANDLE_H
#define ERR_HANDLE_H

#include <stdlib.h>
#include <stdio.h>

#define ERR_NULL_MALLOC(size, func)\
do {                               \
	fprintf("[ERROR] (%s): Could not allocate %zu elements!\n", func, size);\
	exit(EXIT_FAILURE);            \
} while (0)

#endif
