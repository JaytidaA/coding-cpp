#include <stdio.h>
#include <stdbool.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

void reverse(int *start, int *end) {
	int temp;
	while (start < end) {
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
}

void next_permutation(int n, int *a) {
	int brk;
	for (int i = n - 2; i >= 0; i--)
		if (a[i] < a[i + 1]) {
			brk = i;
			break;
		}

	if (brk == -1) {
		reverse(a, a + n - 1);
		return;
	}

	int swap;
	for (int i = n - 1; i >= 0; i--)
		if (a[i] > a[brk]) {
			swap = i;
			break;
		}

	int temp = a[swap];
	a[swap] = a[brk];
	a[brk] = temp;
	reverse(a + brk + 1, a + n - 1);
}

int main(void)
{
	int a[] = {5, 1, 2, 4, 3};
	int n = 5;

	printf("int a[] = "); print_arr(n, a);
	next_permutation(n, a);
	printf("The array after performing the operation is: "); print_arr(n, a);
	return 0;
}
