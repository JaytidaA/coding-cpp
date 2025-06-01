#include <stdio.h>
#include <stdlib.h>
// This is a POSIX library for handling processes
#include <unistd.h>
// This provides the wait() and waitpid() functions
#include <sys/wait.h>

#include <time.h>

/*
 * Problem: Assume you would like to perform some
 * task with different input values. A prints num
 * bers from 1 to 5 while B prints numbers from 6
 * to 10. B waits for A to finish executing before
 * it starts it's own execution.
 */

int main(void)
{
	srand((unsigned) time(NULL));
	int id = fork();
	int n;

	if (id == 0)
		n = 1;
	else
		n = 6;

	if (id != 0) {
		/*
		 * This function makes the calling process
		 * wait for any one of it's children to finish
		 * processing.
		 */
		wait(NULL);
		/*
		 * We can alternatively make use of  waitpid()
		 * to make a process wait for a specific process
		 */
	}

	for (int i = 0; i < 5; i++) {
		printf("%d ", i + n);
		// flush the buffer related to the file stream
		// calling fflush on stdout just prints every-
		// thing in the buffer to the standard output
		fflush(stdout);
		// Adding deliberate delay for randomness
		usleep(rand() % 1000);
		// usleep means micro sleep. \mu looks like u
	}

	if (id != 0)
		putchar('\n');

	return 0;
}
