# Arrays: Easy Questions
Arrays are the most fundamental data structure used in programming, even more so than stacks, queues, maps and graphs. Almost all of the intuition in programming can be thought of and eased into using arrays. Arrays have two main features which make them useful:
1. Store various elements of the same data type.
2. Contiguous allocation of memory.

These two properties are essential to many programming problems and many different data structures which we know and use today are just variations of arrays, or use arrays in one way or the other.

## Largest element in an array
To find the largest element in an array, a single pass is enough.
1. Traverse the array normally, keeping track of the index of the max element.
2. If a larger element is occured at another index, replace the 'max' index with this index.

## Second largest element in an array without sorting
The same technique used in the previous question is required here, with slight changes.
1. In the beginning, assume that the first element to be encountered is both the largest and the second largest element.
2. If a larger element is found while traversing the array, then first store the current value of 'max' in 'second\_max' and then store the new value in 'max'.

## Check if an array is sorted
Just traverse the array and check if the adjacent elements are related to each other or not via a relation which can form a partial ordering on the set. 🥀

## Remove duplicates from a sorted array
Can just go through the array and store the new elements in a hash-map, then remake the new array from the hashmap. But this takes a lot of time as hashmap takes $\mathcal{O}(\lg(n))$ time for the insertion, leading to $\mathcal{O}(n\lg(n))$ time for checking all the elements.

Making use of a two pointer approach as follows:
```c
int remove_duplicates(int n, int a[]) {
    int j = 0, i = j+1;
    while (i < n) {
        if (a[i] != a[j]) {
            a[++j] = a[i++];
            continue;
        }
        while (i < n && a[i] == a[j])
            i++;
    }
    return j;
}
```
## Rotate an array by k places
We can easily rotate an array to the left by 1 place by placing the first element in a temporary variable, and then left shifting the rest of the elements.

We can do the same 'k' times to rotate it by 'k' places. But there is a more efficient solution, it just stores the first 'k' elements in a temporary array, shifts the next n-k elements to the left and then appends the elements stored in the temporary array to the end of the array in order.
The space complexity of this algorithm is $\mathcal{O}(k)$ and time complexity is $\mathcal{O}(n+k)$.

All of this is assuming that 'k' is smaller than the length of the array 'n'.

### Optimal Solution based on observation
We can make use of reversal of arrays in order to find an optimal solution. We look at a test case to have a better understanding.

```c
int a[] = {1, 2, 3, 4, 5, 6, 7};
int n = 7, k = 3;

// After rotating
int a[] = {4, 5, 6, 7, 1, 2, 3};
```

If we perform a reversal on the two parts, the temp array and the final n - k elements of the array, we can see the following results.
```c
int a_partial_reversal[] = {3, 2, 1, 7, 6, 5, 4};
```

If we reverse this partially reversed array completely, then we get the required solution, we can compare with the above code snippet and the one before it to verify this.

## Move zeroes to the end
Given an array, we must move the zeroes to the end while keeping the relative order of the non-zero elements of the array.

A simple intuition would be to just make use of another array and keep track of the realtive order of the non-zero elements in there and then copy it back to the original array, but there is another solution which does not take as much time.

1. Store the number of zeroes encountered in the array in a variable (say 'z')
2. Traverse the array, at each element check if that element is zero or not.
    1. If the elment is a zero, then increment the value of 'z' by one and bring the element which is 'z' places ahead of the current index to the position.
3. Continue until the value of z + iteration index = n - 1;
4. Fill the final 'n - z' places with zeroes.

## Find the union of two arrays
Given two sorted arrays, combine the two arrays in a sorted manner to find the set theoretic union of the two arrays.

We can solve this question as follows:
1. Use the `merge` subroutine from the merge sort algorithm to merge the two arrays into a combined sorted array.
2. Remove the duplicate elements of the sorted array using the `remove_duplicates` method discussed above.

## Find the missing element from the list
Given an array containing 'N-1' integers in the range $[1, N]\cap\mathbb{Z}$. Find the number from 1 to N which is not present in the array.

There are many suboptimal approaches to this solution, for example we can perform a linear search for all elements from 1 to N and then return the value of the element for which linear search returns -1.

Alternatively, we can make use of a hash-map and use it to store the elements which we have encountered and then return the element whose value is zero.

We can also make use of another array which stores the occurrences of the elements like a hash-map with the array indices being the keys and return the element whose value is zero.

### Optimal Solution
We know that the sum of all elements from 1 to N is $\frac{N(N-1)}{2}$, so we can just sum over the array and return the difference between the found sum and this ideal sum. It will be the element which is missing.

## Maximum consecutive ones
We can make use of a simple pass through the array counting the largest sequence of ones. Storing it in a separate variable and then comparing the length of current longest sequence when a '0' is encountered.

Important things to note: Check for a final time that `max = MAX(max, current_max)`. This is required for cases where the last element is a 1, leading the loop to be terminated but the final check between `max` and `current_max` remaining.

## Find number which appears once out of a sea of numbers which appear twice
We can make use of several different techniques but only one of them is optimal.

The first thing which should come to mind is hashing, we can hash the occurrences of the elements in the array (either using an array hash or the hashmap data structure). But this consumes a LOT of space or a LOT of time.

### Optimal Solution
We know that for any number, the bitwise XOR operation of the number with itself is equal to zero. If we perform the bitwise XOR for each element of the array with a particular sum, eventually only a singular number will remain (the one which appeared once).

## Longest subarray with given sum K (Positives)
We need to find the longest subarray of a given array with whose elements sum up to a given sum 'K'.

The first method which comes to mind is to generate all the possible subarrays and then find the length of the maximum value which sums up to 'K'. The code for it is as follows:
```c
#define MAX(x, y) ((x) > (y)) ? (x) : (y)

int longest_subarray_sum(int n, int a[], int k) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        // Starting index of the subarray = i
        for (int j = i; j < n; j++) {
        // Ending index of the subarray = j
            int sum = 0;
            for (int l = i; l <= j; l++)
                sum += a[l];
            // Summing over the entire subarray
            if (sum == k)
                max = MAX(max, j - i + 1);
        }
    }
    return max;
}
```
But this approach is not very optimal, it makes use of three for loops, which makes the time complexity of the order of $\mathcal{O}(n^3)$ with the space complexity being constant or unrelated to the size of the array ($\mathcal{O}(1)$).

### A better solution
A better solution would ideally reduce the time complexity of the algorithm, we can do this by removing one of the loops from the algorithm. The inner loop to sum over the elements can be removed as we can make use of the iteration loop of $j$ in order to sum over the elements as we pass through them. The code for the following is given below:
```c
int longest_subarray_sum_better(int n, int a[], int k) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum == k) {
                max = MAX(max, j - i + 1);
                // We break here because all the elements are positi-
                // ve and if the sum is reached once, we need not ch-
                // eck the next elements in the list.
                break;
            }
        }
    }
    return max;
}
```
This approach now has the time complexity as $\mathcal{O}(n^2)$, with the same auxilliary space requirement of $\mathcal{O}(1)$.

### Optimal solution
The optimal solution involves a two pointer / sliding window approach. We make use of two pointers, same as before, but this only works for a list with positive elements, fortunately the question ensures that we have positive elements. The solution is as follows:

1. Start from the start of the list, keeping the two pointers i and j such that the elements in the range [i, j) are considered for the sum.
2. If the sum of the list of elements is smaller than the required sum, increment j and recompute the sum. Otherwise increment i and recompute the sum.
3. If the sum is equal to the required sum, store the length of the subarray in a variable if it is greater than the current value in that variable and increment both i and j.

```c
int longest_subarray_sum_optimal(int n, int a[], int k) {
    int max = 0;
    int i = 0, j = 1;
    int sum = a[i];
    while ((i < n) && (j < n)) {
        if (sum < k)
            sum += a[j++];
        else if (sum > k)
            sum -= a[i++];
        else {
            max = MAX(max, j - i);
            sum -= a[i++];
            sum += a[j++];
        }
    }
    return max;
}
```
The worst case scenario is that the length of the longest subarray which sums up to k is 1, so 'i' and 'j' constantly follow each other close by, in this case both 'i' and 'j' need to travel ahead by $n$ places and there are approximately $2n$ comparisions, meaning the time complexity of the solution is $\mathcal{O}(n)$.

## Longest subarray with given sum K (Positives and Negatives)
We may now think that the same optimal approach which we applied earlier can be used for this sum as well, but it is not the case, as the optimality depended upon the values of the elements in the list being positive, here the elements in the list are any real numbers. We can still make use of the non-optimal versions with the complexitiies of $\mathcal{O}(n^3)$ and $\mathcal{O}(n^2)$.

We can solve the previous question using a hashmap as well, the solution to that question applies to this one as well as it is essentially the same question.
1. Iterating through the array, store the prefix sums (sum of elements from the first element to the current index) in a map with the prefix sum as the key and the index where that prefix sum was first encountered as the value.
2. At every element, if the prefix sum is 'x', and the value of the required sum is 'k'. Then there must exist some index where the prefix sum 'x-k' should have appeared before. The sum of elements between the indices where 'x-k' and 'x' were the prefix sums, is equal to the required sums.
3. If no such element exists, then either 'x < k' or the required prefix sum does not exist yet.

```cpp
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
```
The above solution's time complexity depends on the type of hashings sturcutre used. Ideally using `std::map` makes it have time complexity $\mathcal{O}(n\lg(n))$. Using `std::unordered_map` makes it have time complexity $\mathcal{O}(n)$ in the case of non-collisions and $\mathcal{O}(n^2)$ otherwise. The space complexity in the worst case is $\mathcal{O}(n)$ as we will store the prefixsums for all the elements of the array.
