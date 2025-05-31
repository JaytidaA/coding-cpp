#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

typedef struct union_len {
	int length;
	int *array;
} unionlen;

unionlen union_arr(int n, int a[], int m, int b[]) {
	int *combined = (int *) malloc(sizeof(int) * (n + m));
	int i = 0, j = 0, com = 0;
	while (i < n && j < m) {
		if (a[i] < b[j])
			combined[com++] = a[i++];
		else
			combined[com++] = b[j++];
	}
	if (i < n)
		while (i < n)
			combined[com++] = a[i++];
	if (j < m)
		while (j < m)
			combined[com++] = b[j++];
	int reduced_size = remove_duplicates(n + m, combined) + 1;
	int *un = (int *) malloc(sizeof(int) * reduced_size);
	for (int i = 0; i < reduced_size; i++)
		un[i] = combined[i];
	free(combined);
	unionlen result;
	result.length = reduced_size;
	result.array = un;
	return result;
}

int main(void)
{
	int n = 10, m = 7;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[] = {2, 3, 4, 4, 5, 11, 12};

	unionlen result = union_arr(n, a, m, b);

	printf("int a[] = "); print_arr(n, a);
	printf("int b[] = "); print_arr(m, b);
	printf("Combined: "); print_arr(result.length, result.array);

	return 0;
}
