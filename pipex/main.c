/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/02/02 01:52:19 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"
#include <errno.h>

void init_file_fd(int ac, char **av, int file_fd[]);
int call_exit(int i);
char *check_executable(char *cmd, char *const *envp);

// 바로 outfile fd로 쓰지 않고 pipe out
int childproc(int fd[], char *command, char **argv)
{
	// 만약 

	// 스탠다드아웃을 파이프아웃으로 넘김
	dup2(fd[PIPE_OUT], STDOUT_FILENO);

	close(fd[PIPE_IN]);
	close(fd[PIPE_OUT]);
	return (execve(command, argv, NULL));
}

int main(int ac, char **av, char **envp)
{
	int 	fd[2];
	pid_t	pid;
	int		infile_fd;
	int		outfile_fd;
	int		i;
	char	**argv;
	char	*command;

	int status;

	infile_fd = open("infile", O_RDONLY);
	//stdin이 infile 가르킴 : infile을 stdin으로 받음
	dup2(infile_fd, STDIN);
	close(infile_fd);
	if (pipe(fd) == -1)
		return (printf("pipe error\n"));
	pipecheck(fd, "parent\n");
	i = 2;
	while (i < ac - 1)
	{
		argv = ft_split(av[i], ' ');
		command = check_executable(argv[0], envp);
		pid = fork();
		if (pid == -1)
			return (printf("forkrerror\n"));
		else if (pid == 0)
		{
			// 스탠다드아웃을 파이프아웃으로 넘김
			dup2(fd[PIPE_OUT], STDOUT_FILENO);
			close(fd[PIPE_IN]);
			close(fd[PIPE_OUT]);
			return (execve(command, argv, NULL));
		}
		waitpid(pid, &status, 0);
		i++;
	}
	//백업본을 스택뜨아웃으로
	dup2(STDOUT_FILENO, fd[STDOUT_COPY]);
	//파이프인을 스탠다드인으로 받아서
	dup2(fd[PIPE_IN], STDIN_FILENO);
	//아웃파일fd로 스탠다드아웃을 넘김
	dup2(STDOUT_FILENO, outfile_fd);
	close(fd[PIPE_OUT]);
	close(fd[PIPE_IN]);
	char *cat = "cat";
	execve("/usr/bin/cat", &cat, NULL);
	close(outfile_fd);
	write(fd[STDOUT_COPY], "finished\n", 10);
	return (0);
}

//infile, outfile 확인 및 fd 반환
void init_file_fd(int ac, char **av, int file_fd[])
{
	if (ac < 3 || access(av[1], F_OK | R_OK) == -1)
		call_exit(1);
	infile_fd = open(av[1], O_RDONLY);
	if (infile_fd < 0)
		call_exit(1);
	outfile_fd = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT | 0644);
	if (outfile_fd < 0 || access(av[ac - 1], F_OK | W_OK) == -1)
	{
		printf("errno : %d\n", errno);
		close(infile_fd);
		call_exit(0);
	}
}

int call_exit(int i)
{
	exit(i);
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

char *check_executable(char *cmd, char *const *envp)
{
	int i = 0;
	char **path;
	char *testcmd;
	
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
	{
		i++;
	}
	path = ft_split_replace(envp[i] + 5, ':', '/');

	i = 0;
	while (path[i])
	{
		testcmd = ft_strjoin(path[i], cmd);
		if (access(testcmd, F_OK | X_OK) != -1)
			break ;
		free(testcmd);
		testcmd = 0;
		i++;
	}
	return (testcmd);
}