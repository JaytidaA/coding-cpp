#include <stdio.h>
#include <stdlib.h>

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

void merge(int n, int left[], int right[], int llen, int rlen) {
	int *a = (int *) malloc(sizeof(int) * n);

	int i = 0, l = 0, r = 0;
	while (l < llen && r < rlen) {
		if (left[l] < right[r])
			a[i++] = left[l++];
		else
			a[i++] = right[r++];
	}
	if (l < llen)
		while (l < llen)
			a[i++] = left[l++];
	else if (r < rlen)
		while (r < rlen)
			a[i++] = right[r++];

	for (int i = 0; i < n; i++)
		left[i] = a[i];

	free(a);
}

void merge_sort_rec(int n, int a[], int start) {
	if (n == 1) return;
	if (n == 2) {
		if (a[start] > a[start + 1])
			swap(&a[start], &a[start+1]);
		return;
	}

	int p = start;
	int llen = n / 2;
	int q = start + llen;
	int rlen = n - llen;

	merge_sort_rec(llen, a, p);
	merge_sort_rec(rlen, a, q);

	merge(n, a + p, a + q, llen, rlen);
}

void merge_sort(int n, int a[]) {
	merge_sort_rec(n, a, 0);
}

int main(void)
{
	int a[] = {5, 1, 2, 4, 3};
	int n = 5;

	printf("Before sorting: ");
	print_arr(n, a);

	merge_sort(n, a);
	printf("After merge sort: ");
	print_arr(n, a);

	return 0;
}
