#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

void move_zeroes(int n, int a[]) {
	int z = 0, i = 0, nz= 0;
	while (i < n) {
		if (!a[i]) {
			z++;
		} else {
			a[nz] = a[nz + z];
			nz++;
		}
		i++;
	}
	for (int i = 0; i < z; i++)
		a[n-i-1] = 0;
}

int main(void)
{
	int a[] = {5, 0, 0, 2, -2};
	int n = 5;

	printf("int a[] = "); print_arr(n, a);
	move_zeroes(n, a);
	printf("Array after moving zeroes one: "); print_arr(n, a);

	return 0;
}
