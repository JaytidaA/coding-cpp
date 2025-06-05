#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int arr[5];
	int len = sizeof(arr) / sizeof(arr[0]);
	srand((unsigned) time(NULL));
	int i;

	for (i = 0; i < len; i++)
		arr[i] = rand() % 100;

	int fd = open("sum", O_WRONLY);
	if (fd == -1) {
		fputs("Error while opening the fifo.\n", stderr);
		exit(EXIT_FAILURE);
	}

	ssize_t n_wr = write(fd, (void *) arr, sizeof(arr));
	if (n_wr == -1) {
		fputs("Error while writing to fifo.\n", stderr);
		exit(EXIT_FAILURE);
	}
	close(fd);
	puts("Wrote to the fifo.");

	return 0;
}
