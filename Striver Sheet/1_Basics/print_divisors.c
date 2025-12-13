#include <stdio.h>
#include <math.h>

int main(void)
{
	int n;
	printf("Enter the numbers to be printed: ");
	scanf("%d", &n);

	for (int i = 1; i < ceil(sqrt(n)); i++)
		if (!(n % i))
			printf("%d %d ", i, n / i);
	putchar('\n');
	return 0;
}
