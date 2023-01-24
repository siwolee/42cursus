/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:56:10 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/25 02:05:07 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

#define FD_READ 0
#define FD_WRITE 1
#define FD_STDOUT 2
#define FD_STDIN 3

int	childproc(int fd[], char *exec)
{
	char args;
	char *path = "/usr/bin/";

	printf("child : start\n");
	write(fd[FD_STDOUT], "child : check FD_STDOUT\n", 25);
	while (read(fd[FD_READ], &c, 20) > 0)
		;
	printf("child : dup2 check : fd_stdout: %d\n", fd[FD_STDOUT]);
	dup2(fd[FD_WRITE], 1);
	return (execve(exec, &arg, &path));
	// dup2(1, fd[FD_STDOUT]);
	// write(1, "child process end\n", 19);
	// write(fd[FD_STDOUT], "child process ...\n", 19);
	// printf("child process end\n");
	// return (0);
}

int parent_start_proc(int fd[], char *infile)
{
	char c;
	int	fd_temp;

	printf("parent : start\n");
	if(access(infile, F_OK | R_OK) == -1)
	{
		printf("infile error\n");
		return (1);
	}
	printf("parent : infile ok\n");
	if (dup2(0, fd[FD_STDIN]) == -1 || dup2(1, fd[FD_STDOUT]) == -1)
	{
		printf("fd dup2 error\n");
		return (1);
	}
	printf("parent : dup ok\n");
	fd_temp = open(infile, O_RDONLY);
	if (fd_temp == -1)
	{
		printf("fd temp open error\n");
		return (1);
	}
	printf("parent : temp ok\n");
	// dup2(fd[FD_WRITE], 1);
	while (read(fd_temp, &c, sizeof(char)) > 0)
	{
		write(fd[FD_WRITE], &c, 1);
	}
	printf("parent : temp ok\n");
	printf("parent : start process ok\n");
	return (0);
}

int parent_end_proc(int fd[], char *outfile, pid_t pid)
{
	int	status;
	char c;
	int fd_temp;

	waitpid(pid, &status,0);
	printf("parent : end process start. pid is%d\n", pid);
	printf("Exit code : %d, signal : %d \n", WEXITSTATUS(status), WTERMSIG(status));
	fd_temp = 20;
	dup2(1, fd[FD_STDIN]);
	if (access(outfile, F_OK | W_OK) == -1)
	{
		printf("parent_end : error access\n");
		return (1);
	}
	fd_temp = open(outfile, O_RDWR | O_CREAT);
	if(fd_temp == -1)
	{
		printf("parent_end : error file\n");
		printf("fd id %d\n", fd_temp);
		write(fd_temp, "check if fd write is wrong\n", 28);
		return (1);
	} 
	while (read(fd[FD_READ], &c, sizeof(char)) > 0)
	{
		write(fd_temp, &c, 1);
	}
	close(fd_temp);
	close(fd[FD_READ]);
	close(fd[FD_WRITE]);
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
	if (parent_start_proc(fd, *av) == 1)
		printf("error\n");
	else
		printf("started\n");
	fd[FD_STDOUT] = fd[1] + 1;
	fd[FD_STDOUT] = dup2(1, fd[FD_STDOUT]);
	write(fd[3], "parent : fd backup fine\n", 25);
	printf("**************\nfirst fd is %d %d %d %d\n", fd[0], fd[1], fd[2], fd[3]);
	pid = fork();
	if (pid == -1)
	{
		printf("parent : fork error\n");
		return (1);
	}
	else if(pid == 0)
		childproc(fd, av[2]);
	else
		parent_end_proc(fd, av[ac -2], pid);
}