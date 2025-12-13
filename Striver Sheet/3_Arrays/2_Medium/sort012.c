#include <stdio.h>
#include <stdbool.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort012(int n, int a[]) {
	int after0 = -1, before2 = n;
	int i = 0;
	while (i < before2) {
		// When "i" reaches "before2", all of the elements are ONLY 2s.
		if (a[i] == 0) {
			// Swap with the element just after "after0"
			swap(&a[i], &a[++after0]);
		} else if (a[i] == 2) {
			// Swap with the element just before "before2"
			swap(&a[i], &a[--before2]);
			i--;
		}
		i++;
	}
}

int main(void)
{
	int a[] = {1, 2, 0};
	int n = 3;

	printf("int a[] = "); print_arr(n, a);
	sort012(n, a);
	printf("The array after sorting is "); print_arr(n, a);
	return 0;
}
