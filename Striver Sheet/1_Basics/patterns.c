#include <stdio.h>
#include <math.h>

void print1(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			putchar('*');
		putchar('\n');
	}
}

void print2(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++)
			putchar('*');
		putchar('\n');
	}
}

void print3(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++)
			printf("%d", j + 1);
		putchar('\n');
	}
}

void print4(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++)
			printf("%d", i + 1);
		putchar('\n');
	}
}

void print5(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - i; j > 0; j--)
			putchar('*');
		putchar('\n');
	}
}

void print6(int n) {
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i; j++)
			printf("%d", j + 1);
		putchar('\n');
	}
}

void print7(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2*n - 1; j++)
			if (j >= n - 1 - i && j <= n - 1 + i)
				putchar('*');
			else
				putchar(' ');
		putchar('\n');
	}
}

void print8(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2*n - 1; j++)
			if (j >= i && j < 2*n - 1 - i)
				putchar('*');
			else
				putchar(' ');
		putchar('\n');
	}
}

void print9(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++)
			if ((j >= fabs((float) n/2 - i - 0.5) - 1) && (j <= (n - 1) - fabs(n/2 - 0.5 - i)))
				putchar('*');
			else
				putchar(' ');
		putchar('\n');
	}
}

void print10(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n + 1) / 2; j++)
			if (j < (n + 1)/2 - fabs(i - n/2))
				putchar('*');
			else
				putchar(' ');
		putchar('\n');
	}
}

void print11(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (j <= i)
				printf("%d ", 1 - ((i + j) % 2));
			else
				printf("  ");
		putchar('\n');
	}
}

void print12(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++)
			if (!(j >= i + 1 && j < 2*n - i - 1))
				printf("%d", (int) (fabs(j + 0.5 - n)) + 1);
			else
				putchar(' ');
		putchar('\n');
	}
}

void print13(int n) {
	int index = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (j <= i)
				printf("%d ", index++);
			else
				printf("  ");
		putchar('\n');
	}
}

void print14(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (j <= i)
				putchar(j + 'A');
			else
				putchar(' ');
		putchar('\n');
	}
}

void print15(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (j < n - i)
				putchar(j + 'A');
			else
				putchar(' ');
		putchar('\n');
	}
}

void print16(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (j <= i)
				putchar(i + 'A');
			else
				putchar(' ');
		putchar('\n');
	}
}

void print17(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2*n - 1; j++)
			if (j >= n - 1 - i && j <= n - 1 + i)
				putchar('A' + i - (int) fabs(n - 1 - j));
			else
				putchar(' ');
		putchar('\n');
	}
}

void print18(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (j <= i)
				putchar('A' - i + n - 1 + j);
			else
				putchar(' ');
		putchar('\n');
	}
}

void print19(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if ((j >= fabs((float) n/2 - i - 0.5)) && (j < n - fabs(n/2 - i - 0.5) - 1))
				putchar(' ');
			else
				putchar('*');
		putchar('\n');
	}
}

void print20(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++)
			if ((i >= n/2 + fabs(j - (float) n / 2)) || (i <= n/2 - fabs(j - (float) n / 2)))
				putchar(' ');
			else
				putchar('*');
		putchar('\n');
	}
}

void print21(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
				putchar('*');
			else
				putchar(' ');
		putchar('\n');
	}
}

void print22(int n) {
	// Here n does not represent number of lines but rather the largest number in the pattern
	for (int i = 0; i < 2*n - 1; i++) {
		for (int j = 0; j < 2*n - 1; j++)
			printf("%d ", 1 + (int) fmax(fabs(n - i - 1), fabs(n - j - 1)));
		putchar('\n');
	}
}

int main(void)
{
	print22(4);
	return 0;
}
