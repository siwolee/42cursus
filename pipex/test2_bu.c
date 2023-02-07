/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/02/02 00:23:50 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"
char *check_executable(char *cmd, char *const *envp)
{
	int i = 0;
	char **path;
	char *testcmd;
	
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
	{
		i++;
	}
	path = ft_split(envp[i] + 5, ':');

	i = 0;
	while (path[i])
	{
		testcmd = ft_strjoin(path[i], cmd);
		if (access(testcmd, F_OK | X_OK) != -1)
			break;
		free(testcmd);
		testcmd = 0;
		i++;
	}
	return (testcmd);
}

int pipecheck(int fd[], char *name)
{
	char c = 1;
	int i;
	i = 1;

	write(fd[PIPE_OUT], "0123456789 ", 12);
	while (c != 0)
	{
		if (read(fd[PIPE_IN], &c, 1) < 0)
			return (write(fd[STDOUT_COPY],"pipecheck error\n", 17));
		write(fd[STDOUT_COPY], &c, 1);
	}
	write(fd[STDOUT_COPY], "pipe check fin : ", 18);
	write(fd[STDOUT_COPY], name, ft_strlen(name));
	return (0);
}

int main(int ac, char **av, char **envp)
{
	int 	fd[4] = {5, 6, 7, 8};
	pid_t	pid;
	int		infile_fd;
	int		outfile_fd;

	int status;

	// init_file_fd(av, ac, *file_fd);
	ac = 1;
	av = 0;
	infile_fd = open("infile", O_RDONLY);
	outfile_fd = open("outfile", O_WRONLY | O_TRUNC | O_CREAT | 0644);
	//STD in/out backup
	dup2(STDIN, fd[STDIN_COPY]);
	dup2(STDOUT, fd[STDOUT_COPY]);
	write(STDOUT, "stdout 1\n", 10);
	write(fd[STDOUT_COPY], "stdout copy 1\n", 15);
	printf("printf 1\n");
	//stdin이 infile 가르킴 : infile을 stdin으로 받음
	dup2(infile_fd, STDIN);
	close(infile_fd);
	if (pipe(fd) == -1)
		return (printf("pipe error\n"));
	pid = fork();
	if (pid == -1)
		return (printf("forkrerror\n"));
	else if (pid == 0)
	{
		char *argv[] = {"grep", "a1", NULL};
	
		dup2(fd[PIPE_OUT], STDOUT);
		dup2(outfile_fd, STDOUT);
		close(fd[PIPE_IN]);
		close(fd[PIPE_OUT]);
		char *command = check_executable("/grep", envp);
		return (execve(command, argv, NULL));
	}
	waitpid(pid, &status, 0);
	close(fd[PIPE_OUT]);
	close(fd[PIPE_IN]);
	return (0);
}
