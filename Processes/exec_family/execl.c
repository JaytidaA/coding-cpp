#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int main(void)
{
	execl(
		"/usr/bin/ping",
		"/usr/bin/ping",
		"google.com",
		NULL
	);
	// execl does not launch a new process but replaces the core
	// image of the current process with the new process image 
	// (here ping). So the next line will not be executed at all
	puts("Ping finished executing.");
	return 0;
}
