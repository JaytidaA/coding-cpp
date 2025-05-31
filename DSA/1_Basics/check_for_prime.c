#include <stdio.h>
#include <math.h>

int main(void)
{
	int n;
	printf("Enter the numbers to be checked: ");
	scanf("%d", &n);

	for (int i = 2; i < ceil(sqrt(n)); i++)
		if (!(n % i)) {
			puts("The number is not a prime.");
			return 0;
		}
	
	puts("The number is a prime.");
	return 0;
}
