#include <stdio.h>
#include <stdbool.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

// a[] is guaranteed to have elements in between 1 and n
int find_missing(int n, int a[]) {
	int sum = 0;
	int ideal_sum = (n * (n + 1)) / 2;
	for (int i = 0; i < n - 1; i++)
		sum += a[i];
	return ideal_sum - sum;
}

int main(void)
{
	int a[] = {5, 1, 2, 4, 3};
	int n = 6;

	printf("int a[] = "); print_arr(n - 1, a);
	printf("The missing element is from [1, %d] is: %d.\n", n, find_missing(n, a));

	return 0;
}
