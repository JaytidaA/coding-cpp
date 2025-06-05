#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * Pipe: It is an in memory file, which is used to perform
 * unidirectional communication between two active processes.
 * It's buffer is present only in memory and destroyed when
 * either process wants to terminate communication.
 *
 * It is different from the pipes which we usually use in the
 * shell using the | character. The shell pipes are built on
 * top of POSIX pipes.
 */

int main(int argc, char *argv[])
{
	int fd[2];
	/*
	 * fd[0] - read
	 * fd[1] - write
	 */

	int status;
	status = pipe(fd);

	if (status == -1) {
		fputs("Error while opening the pipe.\n", stderr);
		exit(EXIT_FAILURE);
	}

	int id = fork();
	if (id == -1) {
		fputs("Error while forking the process.\n", stderr);
		exit(EXIT_FAILURE);
	}

	if (id == 0) {
		// Child will be getting input and pass to parent
		// No need for the writing end of the pipe.
		close(fd[0]);
		int x;
		printf("[child] Write an integer: "); scanf("%d", &x);
		ssize_t nbytes = write(fd[1], &x, sizeof(int));
		if (nbytes == -1) {
			fputs("[child] Error while writing to the pipe!\n", stderr);
			exit(EXIT_FAILURE);
		}
		close(fd[1]);
	} else {
		// Parent will be printing output after performing some operation
		// No need for writing end of pipe.
		close(fd[1]);
		int y;
		ssize_t nbytes = read(fd[0], &y, sizeof(int));
		if (nbytes == -1) {
			fputs("[parent] Error while reading from the pipe!\n", stderr);
			exit(EXIT_FAILURE);
		}
		close(fd[0]);
		printf("[parent] The read integer is %d.\n", y);
	}
	return 0;
}
