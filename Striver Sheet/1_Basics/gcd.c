#include <stdio.h>

int gcd(unsigned int x, unsigned int y)
{
	if (x < y) {
		int temp = x;
		x = y;
		y = temp;
	}

	while (y) {
		int tempx = x;
		x = y;
		y = tempx % y;
	}
	return x;
}

int main(void)
{
	unsigned int n1, n2;
	puts("Enter two numbers to take the GCD of:");
	scanf("%d%d", &n1, &n2);
	if (n1 == 0 || n2 == 0)
		puts("The numbers cannot be zero.");
	printf("The GCD of the two numbers is: %d\n", gcd(n1, n2));
}
