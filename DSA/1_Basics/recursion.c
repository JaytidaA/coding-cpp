#include <stdio.h>

#define RECURSION_DEP 5

void recursion_print(int n) {
	if (n == 0)
		return;
	puts("I use Arch, btw.");
	recursion_print(n - 1);
}

void recursive_call_1_to_(int i, int n) {
	if (i > n) return;
	printf("%d ", i);
	recursive_call_1_to_(i+1, n);
}

void recursion_1_to_(int n) {
	recursive_call_1_to_(1, n);
	putchar('\n');
}

void recursion_1_from_(int n) {
	if (n == 0) return;
	printf("%d ", n);
	recursion_1_from_(n - 1);
}

int sum_first_(int n) {
	return (!n) ? (0) : (n + sum_first_(n-1));
}

int factorial(int n) {
	return (n <= 0) ? (1) : (n * factorial (n - 1));
}

void i_swap (int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void reverse_array_call(int *a, int n, int i) {
	if (i > n / 2) return;
	i_swap(&a[i-1], &a[n-i]);
	reverse_array_call(a, n, i + 1);
}

void reverse_array(int *a, int n) {
	puts("The array before the reversal operation: ");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
	reverse_array_call(a, n, 1);
	puts("The array after  the reversal operation: ");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}

int main(void)
{
	puts("Calling the recursive function:");

	int a[] = {1, 2, 3, 4, 5};
	reverse_array(a, 5);

	return 0;
}
