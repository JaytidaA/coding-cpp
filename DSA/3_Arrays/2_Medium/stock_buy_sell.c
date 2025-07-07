#include <stdio.h>
#include <stdbool.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

int stock_buy_sell(int n, int a[]) {
	int profit = 0;
	/* Naive
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] - a[i] > profit)
				profit = a[j] - a[i];
		}
	}
	*/

	// Better
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] < min)
			min = a[i];
		if (a[i] - min > profit)
			profit = a[i] - min;
	}
	return profit;
}

int main(void)
{
	int a[] = {5, 1, 2, 4, 3};
	int n = 5;

	printf("int a[] = "); print_arr(n, a);

	int max_profit = stock_buy_sell(n, a);
	printf("The maximum profit is: %d.\n", max_profit);
	return 0;
}
