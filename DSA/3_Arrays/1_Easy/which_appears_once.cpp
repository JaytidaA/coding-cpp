#include <unordered_map>
#include <cstdio>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

int which_appears_once(int n, int a[]) {
	std::unordered_map<int, int> count;
	int one;
	for (int i = 0; i < n; i++)
		count[a[i]]++;
	for (auto it: count)
		if (it.second == 1)
			one = it.first;
	return one;
}

int which_appears_once_optimal(int n, int a[]) {
	int sum = a[0];
	for (int i = 1; i < n; i++)
		sum = sum ^ a[i];
	return sum;
}

int main(void)
{
	int a[] = {4, 1, 2, 1, 2};
	int n = 5;

	printf("int a[] = "); print_arr(n, a);
	printf("The number which appears once is %d.\n", which_appears_once_optimal(n, a));
	return 0;
}
