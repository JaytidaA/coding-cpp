#include <stdio.h>
#include <stdbool.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}



int main(void)
{
	int a[] = {5, 1, 2, 4, 3};
	int n = 5;

	printf("int a[] = "); print_arr(n, a);

	printf("The array after performing the operation is: "); print_arr(n, a);
	return 0;
}
