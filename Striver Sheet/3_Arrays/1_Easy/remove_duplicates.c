#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Print array
void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

int remove_duplicates(int n, int a[]) {
	int j = 0, i = j+1;
	while (i < n) {
		if (a[i] != a[j]) {
			a[++j] = a[i++];
			continue;
		}
		while (i < n && a[i] == a[j])
			i++;
	}
	return j;
}

void print_removed(int n, int a[]) {
	int final_index = remove_duplicates(n, a);
	print_arr(final_index + 1, a);
}

int main(void)
{
	int a[] = {1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7};
	int n = 13;

	int b[] = {1, 1};
	int m = 2;

	printf("The non-decreasing array with duplicate elements is: "); print_arr(m, b);
	printf("The same array with duplicates removed is: "); print_removed(m, b);

	return 0;
}
