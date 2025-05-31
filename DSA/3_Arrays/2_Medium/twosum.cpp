#include <vector>
#include <unordered_map>
#include <cstdio>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

std::vector<int> two_sum(std::vector<int> &nums, int target) {
	std::unordered_map<int, int> indices;
	std::vector<int> result;
	for (int i = 0; i < nums.size(); i++) {
		auto elm = indices.find(target - nums[i]);
		if (elm != indices.end()) {
			result.push_back(i); result.push_back(elm->second); break;
		} else
			indices.insert({nums[i], i});
	}
	return result;
}

int main(void)
{
	std::vector<int> a = {2, 7, 11, 15};
	int sum = 9;

	printf("int a[] = "); print_arr(a.size(), a.data());
	std::vector<int> pairs = two_sum(a, sum);
	printf("The pairs of indices which sum up to %d are ", sum); print_arr(pairs.size(), pairs.data());
	return 0;
}
