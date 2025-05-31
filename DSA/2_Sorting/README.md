# Sorting
Sorting is a fundamental operation performed on a list. It is the process of rearranging the elements in a list so that they follow a certain ordering (partial or total). The sorted list of elements usually forms a partially ordered multiset.

## Selection Sort
It is the most basic form of sorting.
1. Initially the entire array is unsorted.
2. While Array is not sorted.
    1. Find the minimum element in the unsorted portion.
    2. Swap the found minimum element with the first element of unsorted array.
    3. Declare the array from the 0th element to the recent minimum sorted.

This type of sort is an in-place sorting algorithm as it does not create an extra copy of the list to be sorted. The time and space complexity of this algorithm is $\mathcal{O}(n^2)$ and $\mathcal{O}(1)$ respectively where 'n' is the number of elements in the list to be sorted.

## Bubble Sort
This is another famous sorting algorithm.
1. Initially the entire array is unsorted.
2. While Array is not sorted.
    1. Start from the beginning to the end of the unsorted portion.
    2. If the elements are out of order. e.g. if a[i] > a[j] for i < j, then swap a[i] and a[j].
    3. Eventually the maximal element in the ordering will reach the final position.
    4. Declare the portion from final part of unsorted array to the end to be sorted.

This algorithm is another type of in-place sorting algorithm with the same time and space complexity constraints of selection sort. The maximum element moves like a bubble through the list to it's correct position.

## Insertion Sort
This is yet another in-place sorting algorithm with $\mathcal{O}(n^2)$ time complexity and $\mathcal{O}(1)$ space complexity.
1. Initially the entire array is unsorted.
2. While Array is not sorted.
    1. Pick the first element from the unsorted portion of the array (say f).
    2. Find the correct position of 'f' in the sorted position and insert the element over there by shifting all the elements above it in the Hasse diagram ahead one position.
    3. If the sorted portion of the array were the first 'r' elements, then the first 'r+1' positions are now to be sorted.

## Merge Sort
Merge sort is a sorting algorithm which is asymptotically efficient. It makes use of divide and conquer approach. It recursively calls itself, breaking down the array into smaller manageable subproblems before combining them back together.
1. Divide the array into two parts
2. Merge Sort the smaller subarrays
3. Merge the smaller subarray as follows:
    1. Have pointers to the first elements of left and right subarrays.
    2. If the element under the pointer appears below the other in the Hasse diagram, add it to the "merged" array, increment that pointer.
    3. Keep doing this until the length of the merged array is equal to sum of lengths of left and right subarrays.

The asymptotic time complexity of this sorting algorithm is $\mathcal{O}(n\lg(n))$ where $n$ is the number of elements in the list, $\lg(n)$ is the logartihm to base 2 of $n$. The asymptotic space complexity of this algorithm is $\mathcal{O}(n)$.

## Quick Sort
Quick sort is an in-place recursive sorting algorithm which is asymptotically efficient most of the time. It makes use of recursion stack only, no extra memory is required. It usually has the time complexity of $\mathcal{O}(n\lg(n))$ but in the worst case scenario is $\mathcal{O}(n^2)$.
1. Select a pivoting element (usually the first element)
2. Find the correct position of the element in the array using a minimum / maximum technique.
3. Rearrange the elements so that the elements to the left of the pivot are below in the Hasse diagram and the elements to the right are above in the Hasse diagram.
4. Recursively sort the subarrays to the left and right of the moved pivot element.

A discussion of the minimum / maximum technique is important as well:
1. Take two pointer indices 'i' and 'j', which travel along the non-pivot elements.
2. First increment 'i' from the start of the array (if pivot is the first element) and keep going ahead until an element in the array is found which is larger than the pivot, stop incrementing 'i'.
3. Decrement 'j' from the end of the array and keep going behind until an element in the array is found which is smaller than the pivot, stop decrementing 'j'.
4. Swap the elements at 'i' and 'j' pointers.
5. Keep going while i <= j. Once i crosses j, replace the element at 'i-1' index with the pivot element.
6. Now the pivot element is in it's correct position as all the elements below it on the Hasse diagram are to it's left and all the elements above it on the Hasse diagram are to the right.
