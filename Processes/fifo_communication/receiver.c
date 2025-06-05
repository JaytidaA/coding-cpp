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
	int i;

	int fd = open("sum", O_RDONLY);
	if (fd == -1) {
		fputs("Error while opening the fifo.\n", stderr);
		exit(EXIT_FAILURE);
	}

	ssize_t n_rd = read(fd, (void *) arr, sizeof(arr));
	if (n_rd == -1) {
		fputs("Error while reading from fifo.\n", stderr);
		exit(EXIT_FAILURE);
	}
	close(fd);
	puts("Received from the fifo.");

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	putchar('\n');

	return 0;
}
