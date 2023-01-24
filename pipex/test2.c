#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

#define FD_READ 0
#define FD_WRITE 1



int	childproc(int fd[2])
{
	char temp[20];
	printf("Child process : receive\n");
	if (dup2(fd[FD_READ], 0) == -1)
		return (1);
	// printf("fd for read is %d\n", fd[FD_READ]);
	read(0, temp, 20);
	printf("%s", temp);
	close(fd[FD_READ]);
	close(fd[FD_WRITE]);
	return (2);
}

int	parentproc(int fd[2])
{
	int *status;
	printf("Parent process : send\n");
	if (dup2(fd[FD_WRITE], 1) == -1)
		return (1);
	printf("fd for write is %d\n", fd[FD_WRITE]);
	write(1, "abcdef\n", 7);
	wait(status);
	return (0);
}

int main(int ac, char **av)
{
	int fd[2];
	pid_t pid;

	if (pipe(fd) == -1)
		return (1);
	printf("Parent : fd for read is %d / write is %d\n", fd[FD_READ], fd[FD_WRITE]);
	pid = fork();
	if (pid  == -1)
	{
		close(fd[FD_READ]);
		close(fd[FD_WRITE]);
		return (1);
	}
	else if (!pid)
		childproc(fd);
	else
		parentproc(fd);
	return (0);
}
