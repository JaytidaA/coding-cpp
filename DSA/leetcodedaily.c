#include <stdio.h>
#include <math.h>

char function(int k)
{
	return (("abbcbccd"[(k - 1) % 8]) + (int) log2((k - 1) / 8));
}

int main(void)
{
	int i;
	printf("Enter a number: ");
	scanf(" %d", &i);
	printf("The character is: %c\n", function(i));
	return 0;
}
