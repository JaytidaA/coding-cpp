#include <stdio.h>
#include <stdbool.h>

#define MAX(x, y) ((x) > (y)) ? (x) : (y)

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

int longest_subarray_sum(int n, int a[], int k) {
	int max = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int l = i; l <= j; l++)
				sum += a[l];
			if (sum == k)
				max = MAX(max, j - i + 1);
		}

	return max;
}

int longest_subarray_sum_better(int n, int a[], int k) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			if (sum == k) {
				max = MAX(max, j - i + 1);
				// We break here because all the elements are positi-
				// ve and if the sum is reached once, we need not ch-
				// eck the next elements in the list.
				break;
			}
		}
	}
	return max;
}

int longest_subarray_sum_optimal(int n, int a[], int k) {
	int max = 0;
	int i = 0, j = 1;
	int sum = a[i];
	while ((i < n) && (j < n)) {
		if (sum < k)
			sum += a[j++];
		else if (sum > k)
			sum -= a[i++];
		else {
			max = MAX(max, j - i);
			sum -= a[i++];
			sum += a[j++];
		}
	}
	return max;
}

int main(void)
{
	int a[] = {5, 1, 2, 4, 3};
	int n = 5;
	int sum = 7;

	printf("int a[] = "); print_arr(n, a);
	printf("The maximum subarray with sum %d is of length %d.\n", sum, longest_subarray_sum_optimal(n, a, sum));
	return 0;
}
