#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

int compare_int(const void *p, const void *q)
{
    if (*(int *) p < *(int *) q)
        return -1;
    else if (*(int *) p == *(int *) q)
        return 0;
    else
        return 1;
}

static inline int MAX(int a, int b) {
    return ((a >= b) ? (a) : (b));
}

int longest_consec(int n, int *a) {
    qsort(a, n, sizeof(int), compare_int);
    int max = 0, i, curr_max = 1;
    for (i = 0; i < n - 1; i++) {
        if (a[i] + 1 == a[i+1])
            curr_max++;
        else if (a[i] == a[i+1])
            continue;
        else {
            max = MAX(max, curr_max);
            curr_max = 1;
        }
    }
	max = MAX(max, curr_max);
    return max;
}

// optimal (using hashing)
struct node {
    int value;
    struct node *next;
};

uint32_t hash(uint32_t x) {
    x = ((x >> 16) ^ x) * 0x45d9f3bu;
    x = ((x >> 16) ^ x) * 0x45d9f3bu;
    x = (x >> 16) ^ x;
    return x;
}

void init_set(int ssize, struct node **restrict set) {
    register int i;
    for (i = 0; i < ssize; i++)
        set[i] = NULL;
}

void insert_set(int ssize, struct node **restrict set, int k) {
    uint32_t index = hash(k);
    index = index % ssize;
    struct node *ptr = set[index];
    if (ptr != NULL) {
        if (ptr->value == k)
            return;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = malloc(sizeof(struct node));
        if (!ptr->next) {
            fputs("Could not mallocate.\n", stderr);
            exit(EXIT_FAILURE);
        }
        ptr->next->value = k;
        ptr->next->next = NULL;
        return;
    }

    ptr = malloc(sizeof(struct node));
    if (!ptr) {
        fputs("Could not mallocate\n", stderr);
        exit(EXIT_FAILURE);
    }
    ptr->value = k;
    ptr->next = NULL;
	set[index] = ptr;
}

bool in_set(int ssize, const struct node **restrict set, int k) {
    uint32_t index = hash(k);
    index = index % ssize;
    const struct node *ptr = set[index];
    while (ptr) {
        if (ptr->value == k)
            return true;
		ptr = ptr->next;
    }
    return false;
}

struct node **hash_set;

int longestConsecutive(int* a, int n) {
    if (!n)
        return 0;
    
    int i;
    int longest = 1;
    hash_set = malloc(n * sizeof(struct node*));
    if (!hash_set) {
        fputs("Could not mallocate\n", stderr);
        exit(EXIT_FAILURE);
    }
    init_set(n, hash_set);
    for (i = 0; i < n; i++) {
        insert_set(n, hash_set, a[i]);
    }

    for (i = 0; i < n; i++) {
		int value = a[i];
        if (!in_set(n, (const struct node **) hash_set, value - 1)) {
            int count = 1;
            int x = value;
            while (in_set(n, (const struct node **) hash_set, x + 1)) {
                ++x;
                ++count;
            }
            longest = MAX(longest, count);
        }
    }
    return longest;
}

void print_hash(int hsize, const struct node **set) {
	int i;
	for (i = 0; i < hsize; i++) {
		const struct node *ptr = set[i];
		while (ptr) {
			printf("[%d] -> ", ptr->value);
			ptr = ptr->next;
		}
		puts("[NULL]");
	}
	putchar('\n');
}

int main(void)
{
	/*
	int a[] = {5, 1, 2, 4, 3};
	int n = 5;
	*/

	int a[] = {100, 4, 200, 1, 3, 2};
	int n = 6;

	printf("int a[] = "); print_arr(n, a);
	printf("The longest possible sequence of consecutive numbers is: %d\n", longestConsecutive(a, n));
	print_hash(n, (const struct node **) hash_set);
	return 0;
}
