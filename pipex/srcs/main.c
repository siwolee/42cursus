/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/29 18:53:54 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char *readpipe(int fd)
{
	int readnum;
	char *buf;
	char *line;
	readnum = 1;
	buf = NULL;
	while (readnum > 0)
	{
		read(fd, buf, 20);
		line = ft_strjoin(line, buf);
	}
	return (line);
}


int parentproc(int fd[], pid_t pid)
{
	int status;
	waitpid(pid, &status, 0);
	printf("result : %s\n", readpipe(fd[FD_RD]));
}
int childproc(int fd[])
{
	pipecheck(fd, "child");
	dup2(1, fd[FD_WR]);
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
	else
		return (parentproc(fd));
}
