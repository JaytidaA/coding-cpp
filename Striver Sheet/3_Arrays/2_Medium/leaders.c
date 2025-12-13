#include <stdio.h>
#include <stdbool.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

/* brute force
void leaders(int n, const int a[]) {
	for (int i = 0; i < n; i++) {
		bool is_leader = true;
		for (int j = i + 1; j < n; j++)
			if (a[i] <= a[j]) {
				is_leader = false;
				break;
			}
		if (is_leader)
			printf(" %d", a[i]);
	}
}
*/

void leaders(int n, const int a[]) {
	int max = n - 1, i;
	for (i = n - 2; i >= 0; i--) {
		if (a[i] > a[max]) {
			printf(" %d", a[max]);
			max = i;
		}
	}
	printf(" %d", a[max]);
}

int main(void)
{
	int a[] = {5, 1, 2, 4, 3};
	int n = 5;

	printf("int a[] = "); print_arr(n, a);
	printf("The leaders of the array are:"); leaders(n, a); putchar('\n');
	return 0;
}
