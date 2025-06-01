#include <stdio.h>
// This is a POSIX library for handling processes
#include <unistd.h>

int main(void) {
	// Child process created
	int id = fork();
	/*
	 * Every line after "forking" a child process
	 * is executed twice, once by the original process
	 * and once by the child process
	 */
	
	/*
	 * Fork returns the PID of the child process to the
	 * parent process but returns 0 inside the child
	 * process
	 */

	if (id == 0)
		puts("Hello from child process.");
	else
		puts("Hello from the main process.");


	if (id != 0)
		fork();
	/*
	 * This line will be printed three times as only
	 * main process will create a child of it's own
	 */
	puts("I use Arch btw.");

	return 0;
}
