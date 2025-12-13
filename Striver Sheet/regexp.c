#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// adjacency list node
// index: index in the array
// patchar: current pattern character
// next: next node
struct node {
    int index;
    char patchar;
    struct node *next;
};

struct node *add_char(struct node *list, int index, char pc)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node) {
        fputs("Could not mallocate!\n", stderr);
        exit(EXIT_FAILURE);
    }

    new_node->index = index;
    new_node->patchar = pc;
    new_node->next = NULL;
    return new_node;
}

struct node *add_star(struct node *list, int index)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node) {
        fputs("Could not mallocate!\n", stderr);
        exit(EXIT_FAILURE);
    }
    
    new_node->index = index;
    new_node->patchar = '*';
    new_node->next = NULL;
    if (!list) {
        fputs("Invalid list! '*' requires a char\n", stderr);
        exit(EXIT_FAILURE);
    }
	list->index--;
    list->next = new_node;
    return list;
}

void free_automaton(struct node **at, int size) {
    struct node *curr;
    struct node *prev;
    for (int i = 0; i < size; i++) {
        curr = at[i];
        prev = NULL;
        if (curr) {
            while (curr) {
                prev = curr;
                curr = curr->next;
                free(prev);
            }
        }
    }
}

bool _strMatch_helper(struct node **, char *, int, int);

bool strMatch(struct node *automaton[], char *s, int numNodes, int alen)
{
	int currIndex = 0;
	bool val = _strMatch_helper(automaton, s, numNodes, currIndex);
	free_automaton(automaton, alen);
	return val;
}

bool _strMatch_helper(struct node *automaton[], char *s, int numNodes, int currIndex)
{
    while (*s) {
		if (!automaton[currIndex])
			break;
		char patchar = automaton[currIndex]->patchar;
		if (patchar == '.' || patchar == *s) {
			currIndex = automaton[currIndex]->index;
		} else if (isupper(patchar)) {
			// it is a dot * xyz pattern
			if (*s != tolower(patchar)) {
				currIndex = automaton[currIndex]->index;
			} else {
				bool intermediate = _strMatch_helper(automaton, s, numNodes, currIndex + 1);
				if (intermediate)
					return true;
				else
					currIndex = automaton[currIndex]->index;
			}
		} else {
			struct node *next_node = automaton[currIndex]->next;
			if (next_node) {
				if (next_node->patchar != '*') {
					fputs("Impossible condition [ch] -> [ch]\n", stderr);
					exit(EXIT_FAILURE);
				}
				currIndex = next_node->index;
				continue;
			} else
				break;
			}
		s++;
	} 

	return ((numNodes == currIndex) && (!(*s)));
}

bool isMatch(char* s, char* p) {
    // create a finite automaton from p
    int alen = strlen(p) + 1;
    struct node *automaton[alen];
    for (int i = 0; i < alen; i++) {
        automaton[i] = NULL;
    }
    int numNodes = -1;
    int currIndex = 0;
	bool final_is_star = false;
    while (*p) {
        if (*p >= 'a' && *p <= 'z') {
            numNodes++;
            automaton[numNodes] = add_char(automaton[numNodes], numNodes + 1, *p);
			final_is_star = false;
        } else if (*p == '.') {
            numNodes++;
			automaton[numNodes] = add_char(automaton[numNodes], numNodes + 1, *p);
			final_is_star = false;
			// check if next is star and more letters
			if (*(p + 1) && *(p + 1) == '*' && *(p + 2)) {
				automaton[numNodes]->patchar = toupper(*(p + 2));
			}
		} else {
            automaton[numNodes] = add_star(automaton[numNodes], numNodes + 1);
			final_is_star = true;
        }
        p++;
    }
	if (!final_is_star)
    	numNodes++;

    // put the string from s into this automaton and check
    return strMatch(automaton, s, numNodes, alen);
}

int main(void)
{
	char *s[] = {"aa", "aa", "abb", "ab", "yz", "aab"};
	char *p[] = {"a", "a*", ".*b", ".*b", ".*", "c*a*b"};
	bool b[] = {false, true, true, true, true, true};
	for (int i = 0; i < 6; i++) {
		if (isMatch(s[i], p[i]) == b[i])
			puts("passed");
		else
			puts("not passed");
	}
	return 0;
}

