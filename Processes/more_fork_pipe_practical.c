#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int arr[] = { 1, 2, 3, 4, 1, 2, 5, 1, 3 };
	int n = sizeof(arr) / sizeof(int); int start, end;

	int fd1[2], fd2[2];
	if (pipe(fd1) == -1) {
		fputs("Error while opening the first pipe.\n", stderr);
		exit(EXIT_FAILURE);
	}

	if (pipe(fd2) == -1) {
		fputs("Error while opening the second pipe.\n", stderr);
		exit(EXIT_FAILURE);
	}

	int id1 = fork();
	if (id1 == -1) {
		fputs("Error while forking a new process first time.\n", stderr);
		exit(EXIT_FAILURE);
	}

	int id2;
	if (id1 != 0) {
		id2 = fork();
		if (id2 == -1) {
			fputs("Error while forking a new process second time.\n", stderr);
			exit(EXIT_FAILURE);
		}
	}
	
	if (id1 == 0) {
		start = 0; end = n/3;
	} else if (id1 != 0 && id2 == 0) {
		start = n/3; end = 2*n/3;
	} else {
		start = 2*n/3; end = n;
	}
	
	int partsum = 0;
	for (int i = start; i < end; i++)
		partsum += arr[i];

	if (id1 == 0) {
		close(fd1[0]);
		close(fd2[0]);
		close(fd2[1]);
		if (write(fd1[1], &partsum, sizeof(int)) == -1) {
			fputs("Error while writing to first pipe!\n", stderr);
			exit(EXIT_FAILURE);
		}
		close(fd1[1]);
	} else if (id1 != 0 && id2 == 0) {
		close(fd1[0]);
		close(fd1[1]);
		close(fd2[0]);
		if (write(fd2[1], &partsum, sizeof(int)) == -1) {
			fputs("Error while writing to second pipe!\n", stderr);
			exit(EXIT_FAILURE);
		}
		close(fd2[1]);
	} else {
		while (wait(NULL) != -1 || errno != ECHILD)
			puts("[parent] Waiting for child to terminate.");

		close(fd1[1]);
		close(fd2[1]);
		int onethirdsum, secondthirdsum;
		if (read(fd1[0], &onethirdsum, sizeof(int)) == -1) {
			fputs("Error while reading from pipe!\n", stderr);
			exit(EXIT_FAILURE);
		}
		close(fd1[0]);

		if (read(fd2[0], &secondthirdsum, sizeof(int)) == -1) {
			fputs("Error while reading from pipe!\n", stderr);
			exit(EXIT_FAILURE);
		}
		close(fd2[0]);

		printf("The final sum of the array is: %d.\n", onethirdsum + secondthirdsum + partsum);
	}

	return 0;
}
