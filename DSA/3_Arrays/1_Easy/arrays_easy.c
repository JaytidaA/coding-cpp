#include <stdio.h>
#include <stdbool.h>

// Print array
void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

// Largest element in an array
int largest_arr(int n, int a[]) {
	int max = 0;
	for (int i = 1; i < n; i++)
		if (a[max] < a[i])
			max = i;
	return a[max];
}

// Second largest element in the array
int second_largest_arr(int n, int a[]) {
	int max = 0, second_max = 0;
	for (int i = 0; i < n; i++)
		if (a[max] < a[i]) {
			second_max = max;
			max = i;
		}
	if (second_max == max) {
		second_max = (max) ? (max - 1) : (max + 1);
		for (int i = 0; i < n; i++) {
			if (i == max)
				continue;
			if (a[second_max] < a[i])
				second_max = i;
		}
	}
	return a[second_max];
}

// Check sortedness of an array in ascending order
bool is_sorted(int n, int a[]) {
	for (int i = 0; i < n-1; i++)
		if (a[i] > a[i+1])
			return false;
	return true;
}

void print_if_sorted(int n, int a[]) {
	bool sorted = is_sorted(n, a);
	if (sorted)
		puts("The given array is sorted.");
	else
		puts("The given array is not sorted");
}

int main(void)
{
	int a[] = {5, 1, 2, 4, 3};
	int b[] = {1, 2, 3, 4, 5};
	int n = 5;

	printf("The array is: ");
	print_arr(n, a);

	printf("The largest element in the array is %d.\n", largest_arr(n, a));

	printf("The second largest element in the array is %d.\n", second_largest_arr(n, a));

	printf("int a[] = "); print_arr(n, a);
	print_if_sorted(n, a);
	printf("int b[] = "); print_arr(n, b);
	print_if_sorted(n, b);

	return 0;
}
