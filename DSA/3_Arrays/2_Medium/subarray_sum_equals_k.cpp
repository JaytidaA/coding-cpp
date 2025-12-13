#include <unordered_map>
#include <vector>
#include <cstdio>

using std::vector;
using std::unordered_map;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> ump;
    int count = 0;
    const int size = nums.size();
    int i = 0;
    for (i = 0; i < size; i++) {
        if (!i)
        	ump[i] = nums[i];
        else
            ump[i] = ump[i-1] + nums[i];
        if (ump[i] == k)
            ++count;
        if (ump.find(ump[i] - k) != ump.end())
            ++count;
    }
    return count;
}

int main(void) {
	vector<int> v = {1, 2, 3};
	int k = 3;
	printf("The number of subarrays with sum = k is: %d\n", subarraySum(v, k));
}
