#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int reverse(int x) {
	// Ensure the edge cases
	if (!x) return x;
	if (x == 1) return 1;
	if (x == -1) return -1;
	if (x == INT_MIN) return 0;

	// Convert to a positive number for the log operation
	_Bool negative = (x < 0);
	if (negative) x *= -1;

	// Get the length for the array
	size_t len;
	len = ceil(log10(x));
	if ((float) x / pow(10, len) == 1.0) len++;

	// Get the digits of the array
	int *digits = (int *) malloc(len * sizeof(int));
	for (int i = 0; i < len; i++) {
		digits[i] = x % 10;
		x /= 10;
	}

	// Find the reverse of the integer
	int n = 0;
	for (int i = 0; i < len; i++) {
		n += digits[i] * pow(10, len-i-1);
	}

	free(digits);
	return n * ((negative)?(-1):(1));
}

int main(void)
{
	int n;
	puts("Give an integer to be reversed");
	scanf("%d", &n);
	printf("The reversed integer is: %d\n", reverse(n));
	return 0;
}
