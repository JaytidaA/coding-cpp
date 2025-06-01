#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(void)
{
	int id1 = fork();
	int id2 = fork();
	if (id1 == 0)
		if (id2 == 0)
			printf("[%d] We are process y\n", getpid());
		else
			printf("[%d] We are process x\n", getpid());
	else
		if (id2 == 0)
			printf("[%d] We are process z\n", getpid());
		else
			printf("[%d] We are parent process\n", getpid());
	while (wait(NULL) != -1 || errno != ECHILD)
		printf("[%d] Waited for a child to terminate.\n", getpid());
	return 0;
}
