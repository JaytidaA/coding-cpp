#include <cstdio>
#include <cmath>
#include <stack>

bool isPalindrome(int x) {
	if (x < 0) return false;
	if (x >= 0 && x < 10) return true;

	int len = std::ceil(std::log10(x));
	if (!(x % (int) pow(10, len))) len++;

	std::stack<int> pal;
	for (int i = 0; i < len / 2; i++) {
		pal.push(x % 10);
		x /= 10;
	}
	if (len % 2) x /= 10;
	int second = (len % 2) ? ((len - 1) / 2) : (len / 2);
	for (int i = 0; i < second; i++) {
		if (pal.top() != (x % 10)) return false;
		x /= 10;
		pal.pop();
	}
	
	return true;
}

bool isPalindromeEfficient(int x) {
	if (x < 0) return false;

	int ori = x;
	int another;
	while (x != 0) {
		another = (another * 10) + (x % 10);
		x /= 10;
	}
	return (ori == another);
}

int main(void)
{
	int n;
	puts("Enter the string to be used as palindrome:");
	scanf("%d", &n);
	printf("The string is ");
	if (!isPalindrome(n))
		printf("not ");
	puts("a palindrome.");
	return 0;
}
