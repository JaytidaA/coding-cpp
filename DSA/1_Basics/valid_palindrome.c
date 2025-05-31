#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define RECURSION_DEP 5

bool isAlphaNumeric(char x) {
    return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'));
}

bool palindromeCheckCall(char *start, char *end) {
    if (start >= end) return true;
    if (*start != *end) return false;
    return palindromeCheckCall(start + 1, end - 1);
}

bool isPalindrome(char* s) {
    char *s1 = (char *) malloc(sizeof(char) * (strlen(s) + 1));
    int i = 0, j = 0;
    while (i < strlen(s) && j < strlen(s))
        if (isAlphaNumeric(s[i]))
            s1[j++] = tolower(s[i++]);
        else
            i++;
    s1[j] = '\0';
	bool a = palindromeCheckCall(s1, s1 + strlen(s1) - 1);
	free(s1);
	return a;
}

int main(void)
{
	puts("Checking if the given string is valid or not: ");
	putchar(isPalindrome("nigga") + '0');
	putchar('\n');
	return 0;
}
