#include <cstdio>
#include <unordered_map>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

int longest_subarray_sum(int n, int a[], int k) {
	int max = 0;
	int sum = 0;
	std::unordered_map<int, int> prefixsums;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum == k)
			max = std::max(max, i + 1);
		auto difference = prefixsums.find(sum - k);
		auto end = prefixsums.end();
		if (difference != end)
			max = std::max(max, i - difference->second);
		if (prefixsums.find(sum) == end)
			prefixsums.insert({sum, i});
	}
	return max;
}

int main(void)
{
	int a[] = {-1, 1, 1};
	int n = 3;
	int sum = 1;

	printf("int a[] = "); print_arr(n, a);
	printf("The maximum subarray with sum %d is of length %d.\n", sum, longest_subarray_sum(n, a, sum));
	return 0;
}
