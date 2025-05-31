# Arrays: Medium Questions
Arrays are the most fundamental data structure used in programming, even more so than stacks, queues, maps and graphs. Almost all of the intuition in programming can be thought of and eased into using arrays. Arrays have two main features which make them useful:
1. Store various elements of the same data type.
2. Contiguous allocation of memory.

These two properties are essential to many programming problems and many different data structures which we know and use today are just variations of arrays, or use arrays in one way or the other.

## Twosum
Check if a pair of elements exists in the array whose sum is equal to 'k'.

We can do this easily by generating all the pairs but the time complexity is $\mathcal{O}(n^2)$ where $n$ is the number of elements in the array.

Another approach is to use a hashmap. Store all the encountered elements in the hashmap along with their indices as the value. For a suitable pair to exist in the array, if the current element which is being iterated over is a[i] then the element 'k - a[i]' should also exist in the array. The time complexity of this algorithm is $\mathcal{O}(n\lg(n))$ with constant auxilliary space.

## Sort an arrays of 0s, 1s, 2s
The usual sorting algorithms require atleast $n\lg(n)$ time in order to sort a list. But since there are only a few possible elements, maybe we can come up with some other way to sort the elements which is linear in the number of elements.

We observe that there are only three numbers, so we can make use of two partitioning indices in order to partition the 0s, 1s and 2s.

```c
void sort012(int n, int a[]) {
    int after0 = -1, before2 = n;
    int i = 0;
    while (i < before2) {
        // When "i" reaches "before2", all of the elements are ONLY 2s.
        // No need to check all the elements as it will "unsort" the array.
        if (a[i] == 0) {
            // Swap with the element just after "after0"
            swap(&a[i], &a[++after0]);
        } else if (a[i] == 2) {
            // Swap with the element just before "before2"
            swap(&a[i], &a[--before2]);
            i--;
        }
        i++;
    }
}
```
