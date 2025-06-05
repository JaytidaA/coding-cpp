#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

/*
 * stat.h is used to provide a data structure 
 * that stores metadata about files just like
 * how file streams and file descriptors are
 * used to provide access to underlying file
 * data.
 */

/*
 * types.h contains defnitions for system
 * specific integral types used to store ids
 * for processes, users and groups.
 */

/*
 * errno.h is a header file used to provide
 * the errno symbol. It builds upon the ISO C
 * definition of errno.h which is only
 * required to define EDOM, EILSEQ and ERANGE
 * . POSIX requires that a few more error nos
 * be defined.
 */

/*
 * fcntl.h is the file control header. It
 * defines a lot of macros and structures for
 * file control, file locking and unlocking.
 */

int main(int argc, char *argv[])
{
	if (mkfifo("my_fifo", 0777) == -1 && errno != EEXIST) {
		puts("Could not create fifo file.\n");
		exit(EXIT_FAILURE);
	}

	puts("Opening...");
	int fd = open("my_fifo", O_WRONLY);
	if (fd == -1) {
		fputs("Error while opening the fifo.\n", stderr);
		exit(EXIT_FAILURE);
	}
	puts("Opened...");
	// Each call to "open" a fifo leads to blocking of
	// the reader or writer thread until the other end
	// is also opened.

	int x = 97;
	if (write(fd, &x, sizeof(x)) == -1) {
		puts("Error while writing to file.\n");
		exit(EXIT_FAILURE);
	}
	puts("Written...");
	
	close(fd);
	puts("Closed...");
	return 0;
}
