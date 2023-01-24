#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

#define FD_READ 0
#define FD_WRITE 1

int main(int ac, char **av)
{
	av++;
	if (access("bunny.c", F_OK | X_OK) == -1)
		return (1);
	if (execve("/usr/bin/gcc", av, NULL) == -1)
	{
		printf("gcc failed\n");
		return (1);
	}
	printf("sucess\n");
	return (0);
}
