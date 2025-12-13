#include <stdio.h>
#include <stdbool.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

int linear_search(int n, int a[], int k) {
	for (int i = 0; i < n; i++)
		if (a[i] == k)
			return i;
	return -1;
}

void print_result_search(int n, int a[], int k) {
	int res = linear_search(n, a, k);
	if (res == -1)
		printf("The given element %d does not exist in the array.\n", k);
	else
		printf("The index of %d in the a is: %d.\n", k, res); 
}

int main(void)
{
	int a[] = {1, 2, 3, 4, 5};
	int n = 5;
	int k1 = 4, k2 = 7;

	printf("int a[] = "); print_arr(n, a);
	print_result_search(n, a, k1);
	print_result_search(n, a, k2);
	return 0;
}
