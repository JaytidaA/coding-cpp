#include <stdio.h>
#include <stdlib.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

int *rearrange(int n, int *a) {
	int *new = (int *) malloc(n * sizeof(int));
	int pos = 0, neg = 1;

	for (int i = 0; i < n; i++)
		if (a[i] > 0) {
			new[pos] = a[i];
			pos += 2;
		} else {
			new[neg] = a[i];
			neg += 2;
		}

	return new;
}

int main(void)
{
	int a[] = {1, 2, -4, -5};
	int n = 4;

	printf("int a[] = "); print_arr(n, a);
	int *new = rearrange(n, a);
	printf("The array after performing the operation is: "); print_arr(n, new);
	free(new);
	return 0;
}
