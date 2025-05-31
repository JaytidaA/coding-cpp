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

void selection_sort(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;
		swap(&a[i], &a[min]);
	}
}

void rec_bubble_sort(int n, int a[]) {
	if (n == 1)
		return;
	for (int j = 0; j < n - 1; j++)
		if (a[j] > a[j+1])
			swap(&a[j], &a[j+1]);
	rec_bubble_sort(n-1, a);
}

void rec_insertion_sort(int n, int a[], int i) {
	if (i >= n - 1)
		return;
	int f = a[i+1];
	int j;
	for (j = i; j >= 0; j--)
		if (f <= a[j])
			a[j+1] = a[j];
		else
			break;
	a[j+1] = f;
	rec_insertion_sort(n, a, i+1);
}

int main(void)
{
	int a[] = {5, 1, 2, 4, 3};
	int b[] = {5, 1, 2, 4, 3};
	int c[] = {5, 1, 2, 4, 3};
	int n = 5;

	printf("Before sorting: ");
	print_arr(n, a);

	selection_sort(n, a);
	printf("After selection sort: ");
	print_arr(n, a);
	
	rec_bubble_sort(n, b);
	printf("After recursive bubble sort: ");
	print_arr(n, b);

	rec_insertion_sort(n, c, 0);
	printf("After recursive insertion sort: ");
	print_arr(n, c);

	return 0;
}
