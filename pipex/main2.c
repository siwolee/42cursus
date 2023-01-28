/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/29 00:04:31 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>

#define FD_RD 0
#define FD_WR 1
#define FD_OUT 2
#define FD_IN 3

#define BUFSIZE 20

int pipecheck(int fd[], char *name);

char *readpipe(int fd)
{
	int readnum;
	char *buf;
	char *line;
	readnum = 1;
	while (readnum > 0)
	{
		read(fd[FD_READ], buf, 
	}


int childproc(int fd[])
{
	pipecheck(fd, "child");
	dup2(fd[FD_WR], 1);
	printf("child proc sending\n");
	return (0);
}

int pipecheck(int fd[], char *name)
{
	int i = 0;
	char c = 0;

	write(fd[FD_WR], "0123456789 ", 11);
	while (i < 11)
	{
		read(fd[FD_RD], &c, 1);
		printf("%c", c);
		i++;
	}
	printf("pipe check fin : %s\n", name);
	return (0);
}

int main()//int ac, char ** av)
{
	int 	fd[4];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (1);
	pipecheck(fd, "parent");
	pid = fork();
	if (pid == -1)
		return (printf("forkrerror\n"));
	else if (pid == 0)
		return (childproc(fd));
	//readpipe(fd);
}
