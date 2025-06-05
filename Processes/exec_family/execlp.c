#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int main(void)
{
	execlp(
		"ping",
		"ping",
		"google.com",
		NULL
	);
	// execlp does the same thing as execl but loads in the
	// environment variable $PATH from our shell.
	puts("Ping finished executing.");
	return 0;
}
