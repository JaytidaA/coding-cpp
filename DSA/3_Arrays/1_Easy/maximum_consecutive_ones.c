#include <stdio.h>
#include <stdbool.h>

#define MAX(x,y) ((x) > (y)) ? (x) : (y)

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

int maximum_consecutive_ones(int n, int a[]) {
	int max = a[0], current_max = a[0];
	for (int i = 1; i < n; i++)
		if ((a[i] == 1) && (a[i-1] == 0))
			current_max = 1;
		else if ((a[i] == 1) && (a[i-1] == 1))
			current_max += 1;
		else {
			max = MAX(max, current_max);
			current_max = 0;
		}
	max = MAX(max, current_max);
	return max;
}

int main(void)
{
	int a[] = {1, 1, 0, 1, 1, 1};
	int n = 6;

	printf("int a[] = "); print_arr(n, a);
	printf("The array has %d consecutive ones.\n", maximum_consecutive_ones(n, a));
	return 0;
}
