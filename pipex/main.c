#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

#define FD_READ 0
#define FD_WRITE 1
#define FD_STDIN 2
#define FD_STDOUT 3

int	childproc(int fd[], int i, char *exec)
{
	char **arg;
	char *path = "/usr/bin/";
	char *c;

	arg = malloc(sizeof (char *));
	*arg = malloc(sizeof (char) * 20);
	read(fd[FD_READ], *arg, 20);
	dup2(fd[FD_READ], 0);
	dup2(fd[FD_WRITE], 1);
	close(fd[FD_READ]);
	printf("child process end\n");
	if (execve(exec, arg, &path))
		return (1);
	return (0);
}

int parent_start_proc(int fd[], char *infile)
{
	int	status;
	char *c;
	int	fd_temp;

	if(access(infile, F_OK | R_OK) == -1)
	{
		printf("infile error\n");
		return (1);
	}
	dup2(0, fd[FD_STDIN]);
	dup2(1, fd[FD_STDOUT]);
	fd_temp = open(infile, O_RDONLY);
	if (fd_temp == -1)
	{
		printf("fd temp open error\n");
		return (1);
	}
	dup2(fd[FD_WRITE], 1);
	while (read(fd_temp, c, sizeof(char)) > 0)
	{
		write(1, c, 1);
	}
	dup2(1, fd[FD_STDOUT]);
	printf("parent : start process\n");
	return (0);
}

int parent_end_proc(int fd[], char *outfile, pid_t pid)
{
	int	status;
	char *c;

	printf("parent : end process\n");
	if(access(outfile, F_OK) == -1)
		fd[FD_READ] = open(outfile, O_CREAT);
	else
		fd[FD_READ] = open(outfile, O_RDWR);
	if(fd[FD_READ] != -1 || access(outfile, F_OK | W_OK) == -1)
		return (1);
	waitpid(pid, &status, 0);
	printf("Exit code : %d, signal : %d \n", WEXITSTATUS(status), WTERMSIG(status));
	fd[FD_READ] = open(outfile, O_CREAT);
	dup2(fd[FD_READ], 0);
	while (read(1, c, sizeof(char)) > 0)
	{
		write(1, c, 1);
	}
	close(fd[FD_READ]);
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	int fd[4];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		printf("nopipe");
		return (1);

	}
	av++;
	printf("piped\n");
	parent_start_proc(fd, *av);
	pid = fork();
	if (pid == -1)
		return (1);
	else if(pid == 0)
		childproc(fd, 0, av[2]);
	else
		parent_end_proc(fd, av[ac -2], pid);
}
