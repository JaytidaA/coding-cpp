#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/*
 * Imagine you would like to perform addition of array elements.
 * We can make use of different processors on multiprocessor
 * systems. One process will compute sum of the first half and 
 * the other process will compute the sum of the second half of
 * the array. One of the process will send it's partial sum over
 * to the other via a pipe and then compute them together.
 */

int main(int argc, char *argv[])
{
	int arr[] = { 1, 2, 3, 4, 1, 2 };
	int n = sizeof(arr) / sizeof(int); int start, end;
	int fd[2];
	if (pipe(fd) == -1) {
		fputs("Error while opening the pipe.\n", stderr);
		exit(EXIT_FAILURE);
	}

	int id = fork();
	if (id == -1) {
		fputs("Error while forking a new process.\n", stderr);
		exit(EXIT_FAILURE);
	}

	
	if (id == 0) {
		start = 0; end = n/2;
	} else {
		start = n/2; end = n;
	}
	
	int partsum = 0;
	for (int i = start; i < end; i++)
		partsum += arr[i];

	if (id == 0) {
		close(fd[0]);
		if (write(fd[1], &partsum, sizeof(int)) == -1) {
			fputs("Error while writing to pipe!\n", stderr);
			exit(EXIT_FAILURE);
		}
		close(fd[1]);
	} else {
		wait(NULL);
		close(fd[1]);
		int halfsum;
		if (read(fd[0], &halfsum, sizeof(int)) == -1) {
			fputs("Error while reading from pipe!\n", stderr);
			exit(EXIT_FAILURE);
		}
		close(fd[0]);
		printf("The final sum of the array is: %d.\n", halfsum + partsum);
	}

	return 0;
}
