#include <cstdio>
#include <map>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

int majority_element(int n, int a[]) {
	std::map<int, int> counts;
	int max = 0, maxval = 0;
	for (int i = 0; i < n; i++)
		counts[a[i]]++;
	for (std::map<int, int>::iterator it: counts)
		if (it->second > maxval) {
			max = it->first;
			maxval = it->second;
		}
	return max;
}

int main(void)
{
	int a[] = {5, 1, 2, 5, 5};
	int n = 5;

	printf("int a[] = "); print_arr(n, a);
	printf("The majority element of the above array is %d.\n", majority_element(n, a));
	return 0;
}
