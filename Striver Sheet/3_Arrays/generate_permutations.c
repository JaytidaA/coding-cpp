/* A small file to generate permutations of given input numbers */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_integers(const void *p, const void *q);
void print_arr(size_t n, const int a[]);
void generate_permutations(size_t n, int a[]);
void _generate_helper(size_t, int a[], size_t first);
void swap(int *a, int *b);

int main(int argc, char *argv[])
{
	if (argc == 1) {
		fprintf(stderr, "Usage: %s (list: int)\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	int arr[argc - 1], i;
	for (i = 1; i < argc; i++)
		arr[i - 1] = atoi(argv[i]);

	qsort(arr, argc - 1, sizeof(int), compare_integers);
	generate_permutations(argc - 1, arr);
}

/* compare_integers: comparator function for integers */
int compare_integers(const void *p, const void *q)
{
	if (*(int *) p < *(int *) q)
		return -1;
	else if (*(int *) p == *(int *) q)
		return 0;
	else
		return 1;
}

/* print_arr: prints an array to the standard output */
void print_arr(size_t n, const int a[])
{
	if (n == 0) {
		puts("[]"); return;
	}
	printf("[%3d", a[0]);
	for (size_t i = 1; i < n; i++)
		printf(", %3d", a[i]);
	puts("]");
}

void generate_permutations(size_t n, int a[])
{
	_generate_helper(n, a, 0);
}

/* recursive helper function for actually generating permutations */
void _generate_helper(size_t n, int a[], size_t first)
{
	print_arr(n, a);
	if (first == n)
		return;
	for (size_t i = first; i < n; i++) {
		swap(&a[first], &a[i]);
		_generate_helper(n, a, first + 1);
		swap(&a[first], &a[i]);
	}
}

/* swap: swaps two integers */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
