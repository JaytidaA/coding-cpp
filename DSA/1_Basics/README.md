# Introduction
The introduction to basic Data Structures and Algorithms

## Basic Patterns
Usually we print patterns to increase our knowledge and handiness with loops.

There usually exist two loops in the patterns.
1. Outer loop: For the rows / number of lines.
2. Inner loop: For each column in a row. Connect the columns somehow to the rows.
3. Printing to be performed in inner loop.
4. Observe symmetry if present.

## STL in C++ (Which I will be barely using)
The C++ Standard Template Library (STL) consists of four major blocks.
Algorithms, Containers, Functors and Iterators. We will learn mostly about containers rn.

1. Pair: Is a pair of elements. Can be used to store two elements together. Like points in the 2-D plane. Extends to more elements using the "arrays" or "tuple" data structure.

2. Vector: A Random Access Dynamic Array. Makes use of arrays internally as well with constant reallocation and moving of elements to maintain the effective of resizeability.

3. List: Makes use of Linked Lists internally and is used similarly to vectors. The main problem is that insertion and deletion takes linear time as compared to constant for vectors. Only the remove/erase operation invalidates any iterators to the elements as compared to the vectors where almost any insertion, deletion or moves invalidates the vectors.

4. Deque: Is an array based implementation of a List, basically it also uses arrays internally but also allows inserts and deletions at the beginning with the use of the emplace\_front and the push\_front methods.

5. Stack: A LIFO data structure. Provides basic operations such as push(), pop() and top().

6. Queue: A FIFO data structure. Provides basic operations such as push() (enqueue), pop() (dequeue), and front() and back().

7. Priority queue: A Queue which pops elements based on some sorting or indexing. We must provide the sorting functor or function if we are storing classes of custom objects. It may make use of an array or a heap but it is guaranteed to have O(lg(n)) asymptotic time complexity in the worst cases.

8. Set: A well-defined collection of objects. Stores elements in the sorted order. Does not allow duplicates of elements. Does not give an error if trying to store multiple elements but silently discards it. The count operation on an element always gives 1.
* The set is ordered. Uses Heap internally so insertions and deletions require O(lg(n)) time. The erase operation works as expected. The find operation takes requires logarithmic time complexity.

9. Multiset: A well-defined collection of objects with duplicates of the same elements allowed to be stored. The count operation gives the number of occurences of the given element in the set.

10. Unordered Set: Set but unordered.
* Ensures non-duplication of items while ensuring constant access to the elements.
* Lower bound and upper bound operations do not work.

11. Map: Hashmap. Sorts according to the keys.
* The syntax uses arrays for insertion and deletions. map.insert({ list of elements }).
* For access and another type of insertion, the array subscripting syntax is used for accessing the values when a key is known.
* The iterators to the elements are actually iterators to elements which contain a first and second data member which we can use in the same way as a pair.
* Works in logarithmic time.

12. Multi-map: Multiple hashmap. Can stored duplicate keys.
* map[key] cannot be used to access elements.

13. Unordered map: Unordered hashmap.
* Works in constant time until it takes linear time (which happens once in a blue moon).

## Basic Mathematics
1. Count Digits: The number of digits (of a positive integer) in a number in decimal notation is the floor of the logarithm of that number.
2. Reverse the number: This makes use of a two pass approach. In one pass, the digits of the number are extracted, in the next pass the reversed number is created while making sure that the range of 32-bit signed numbers in 2's-complement encoding is not violated.
3. Check Palindrome: Make use of a stack to check if a string is a palindrome or not.

## Hashing
1. Hashing is an important technique used to store key value pairs (like an array but instead of integer subscripts, any data type can be used as keys).
