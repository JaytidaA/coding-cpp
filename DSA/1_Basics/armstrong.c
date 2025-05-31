#include <stdio.h>
#include <math.h>

int armstrong(int x)
{
	int len = ceil(log10(x));
	if (!(x % (int) pow(10, len))) len++;

	int sum = 0, tempx = x;
	while (tempx) {
		sum += (int) pow((double) (tempx % 10), len);
		tempx /= 10;
	}

	return (sum == x);
}

int main(void)
{
	int n;
	puts("Enter the number to find if it is Armstrong or not:");
	scanf("%d", &n);
	printf("The number is ");
	if (!armstrong(n))
		printf("not ");
	printf("an Armstrong number\n");
}
