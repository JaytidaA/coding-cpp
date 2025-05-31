#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

void rot_left_arr(int n, int a[]) {
	int first = a[0];
	for (int i = 0; i < n - 1; i++)
		a[i] = a[i+1];
	a[n-1] = first;
}

void rot_left_multiple(int n, int a[], int k) {
	int *first_few = (int *) malloc(k * sizeof(int));
	for (int i = 0; i < k; i++)
		first_few[i] = a[i];
	for (int i = 0; i < n - k; i++)
		a[i] = a[i+k];
	for (int i = 0; i < k; i++)
		a[n-k+i] = first_few[i];
	free(first_few);
}

void reverse_arr(int n, int a[]) {
	int *cpy = (int *) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		cpy[i] = a[i];
	for (int i = 0; i < n; i++)
		a[i] = cpy[n-i-1];
	free(cpy);
}

void rot_left_optimal(int n, int a[], int k) {
	k = k % n;
	reverse_arr(k, a);
	reverse_arr(n - k, a + k);
	reverse_arr(n, a);
}

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {6, 7, 8, 9, 10};
	int c[] = {11, 12, 13, 14, 15};
	int n = 5, k = 3;

	printf("int a[] = "); print_arr(n, a);
	rot_left_arr(n, a);
	printf("Array after rotating once: "); print_arr(n, a);


	printf("int b[] = "); print_arr(n, b);
	rot_left_multiple(n, b, k);
	printf("Array after rotating %d times: ", k); print_arr(n, b);

	printf("int c[] = "); print_arr(n, c);
	rot_left_optimal(n, c, k);
	printf("Array after rotating %d times: ", k); print_arr(n, c);

	return 0;
}
