#include <bits/stdc++.h>

int main(void)
{
	std::vector<int> vec1 = {10, 5, 10, 15, 10, 5};
	std::vector<int> vec2 = {2, 2, 3, 4, 4, 2};

	const std::vector<int> &vec = vec2;

	std::unordered_map<int, int> count;
	for (int i = 0; i < vec.size(); i++) {
		count[vec[i]]++;
	}

	for (auto it: count) {
		std::cout << it.first << " -> " << it.second << "\n";
	}
}
