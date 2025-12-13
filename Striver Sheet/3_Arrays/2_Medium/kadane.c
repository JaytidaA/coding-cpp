#include <stdio.h>
#include <stdbool.h>

#define MAX(x, y) ((x) > (y)) ? (x) : (y)

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

typedef struct kadane_indices {
	int first;
	int aftersecond;
} indices;

indices maximum_subarray_sum(int n, int a[]) {
	int max = 0;
	int i = 0, j = 1;
	int k = 0;
	int sum = 0;
	// [i, j)
	while (k < n) {
		if (sum + a[k] < a[k]) {
			sum = a[k];
			if (max < sum) {
				max = sum;
				i = k; j = k + 1;
			}
		} else {
			sum += a[k];
			if (max < sum) {
				max = sum;
				j++;
			}
		}
		k++;
	}
	indices kadane;
	kadane.first = i;
	kadane.aftersecond = j;
	return kadane;
}

int main(void)
{
	int a[] = {5, 1, 2, 4, 3};
	int n = 5;

	int b[] = {-1, 2, 2, -1};
	int m = 4;

	printf("int a[] = "); print_arr(m, b);
	indices solution = maximum_subarray_sum(m, b);
	printf("The maximum subarray is "); print_arr(solution.aftersecond - solution.first, b + solution.first);
	return 0;
}
