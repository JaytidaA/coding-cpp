#include <stdio.h>
#include <stdlib.h>
// This is a POSIX library for handling processes
#include <unistd.h>
// This provides the wait() and waitpid() functions
#include <sys/wait.h>

#include <time.h>

int main(void)
{
	int id = fork();
	// getpid(): get the pid of the current process
	// getppid(): get the pid of the parent of the current process
	if (id == 0) {
		// Forcefully sleeping so that parent terminates before child
		sleep(1);
		/*
		 * Since parent process ends before child,
		 * the child may become a zombie so a new
		 * parent is assigned to the child.
		 *
		 * This behavious is implementation dependent.
		 */
	}
	printf("Get PID: %d Parent PID: %d\n", getpid(), getppid());

	// Wait for a child to terminate.
	// Main process will not terminate abruptly now.
	// Child process does not have any children to
	// wait for so wait just returns an error number
	// and leaves.
	int res = wait(NULL);
	if (res == -1) {
		puts("[child] No children to wait for.");
	}
	else {
		printf("[parent] %d finished execution.\n", res);
	}
	return 0;
}
