#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n - 1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

void quick_sort_rec(int a[], int low, int high) {
	if (low >= high)
		return;
	int pivot = low;
	int i = pivot + 1;
	int j = high;
	while (i < j) {
		if (a[i] <= pivot && i < high) {
			i++; continue;
		}
		if (a[j] >= pivot && j > low) {
			j--; continue;
		}
		swap(&a[i], &a[j]);
	}
	swap(&a[i], &a[pivot]);
	quick_sort_rec(a, low, i-1);
	quick_sort_rec(a, i, high);
}

void quick_sort(int n, int a[]) {
	quick_sort_rec(a, 0, n-1);
}

int main(void)
{
	int a[] = {5, 1, 2, 4, 3};
	int n = 5;

	printf("Before sorting: ");
	print_arr(n, a);

	quick_sort(n, a);
	printf("After quick sort: ");
	print_arr(n, a);

	return 0;
}
