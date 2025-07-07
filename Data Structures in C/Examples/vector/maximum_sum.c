/*
 * maximum_sum.c
 * Example of Vectors solving the maximum sum subarray problem.
 * Author: https://github.com/JaytidaA/
 */

#include "vector/vector.h"
#include "vector/vector_utils.h"
#include <stdio.h>

void maximum_sum_subarray(Vector *v)
{
	int sum = *front(v);
	int maxsum = *front(v);
	int next;
	int start = 0, length = 1;
	for (int i = 1; i < size(v); i++) {
		next = *at_ptr(v, i);
		if (next > sum + next) {
			start = i;
			length = 1;
			sum = next;
		} else {
			length += 1;
			sum = sum + next;
		}

		if (maxsum < sum)
			maxsum = sum;
	}
	printf("The subarray with the maximum sum is: ");
	Vector temp = (Vector) { .arr = (v->arr + start), .size = length };
	print_vector(&temp);
	printf("The maximum sum is: %d\n", maxsum);
}

int main(void)
{
	int num = 0;
	Vector *vec = new_vector();

	printf("Enter a set of numbers (0 to stop): ");
	do {
		scanf("%d", &num);
		push_back(vec, num);
	} while (num != 0); 

	// Pop back the final zero which was pushed
	pop_back(vec);

	if (empty(vec)) {
		printf("Enter at least one number!\n");
		return 1;
	}

	maximum_sum_subarray(vec);

	delete_vector(vec);
	return 0;
}
