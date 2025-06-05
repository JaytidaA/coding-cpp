#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>
#include <sys/wait.h>

// Two process: A and B, A sends a number, B receives
// it and multiplies it by 4 and sends it back to A.

int main(int argc, char *argv[])
{
	int p1[2];
	if (pipe(p1) == -1) {
		fputs("Could not create pipe.\n", stderr); exit(EXIT_FAILURE);
	}

	int p2[2];
	if (pipe(p2) == -1) {
		fputs("Could not create pipe.\n", stderr); exit(EXIT_FAILURE);
	}

	int pid = fork();
	if (pid == -1) {
		fputs("Could not create child process.\n", stderr); exit(EXIT_FAILURE);
	}

	if (pid == 0) {
		// Child process
		close(p1[1]);
		close(p2[0]);
		int x;
		if (read(p1[0], (void *) &x, sizeof(x)) == -1) {
			fputs("[child] Error while reading data.\n", stderr); exit(EXIT_FAILURE);
		}
		close(p1[0]);
		x *= 4;
		if (write(p2[1], (void *) &x, sizeof(x)) == -1) {
			fputs("[child] Error while writing data.\n", stderr); exit(EXIT_FAILURE);
		}
		close(p2[1]);
	} else {
		// Parent process
		close(p1[0]);
		close(p2[1]);
		int x;
		printf("Enter a number to be multiplied by 4: "); scanf("%d", &x);
		if (write(p1[1], (void *) &x, sizeof(x)) == -1) {
			fputs("[parent] Error while writing data.\n", stderr); exit(EXIT_FAILURE);
		}
		close(p1[1]);
		int y;
		if (read(p2[0], (void *) &y, sizeof(y)) == -1) {
			fputs("[parent] Error while reading data.\n", stderr);
		}
		close(p2[0]);
		printf("The modified integer is %d.\n", y);
		wait(NULL);
	}
	
	return 0;
}
