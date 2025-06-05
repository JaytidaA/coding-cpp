#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int main(void)
{
	char *arr[] = {
		"/usr/bin/ping",
		"google.com",
		NULL
	};

	execv(
		"/usr/bin/ping",
		arr
	);

	// execv does the same thing as execl but uses a "vector"
	// of arguments much in the same way as int argc and char
	// * argv[] used in C programs.
	puts("Ping finished executing.");
	return 0;
}
