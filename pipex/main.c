/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/31 14:29:40 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void *init_file_fd(int ac, char **av, int file_fd[]);
int call_exit(int i);


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


// 바로 outfile fd로 쓰지 않고 pipe out
int childproc(int fd[], int outfile_fd, char *const *envp)
{
	char *argv[] = {"grep", "a1", NULL};
	dup2(fd[PIPE_OUT], STDOUT);
	dup2(outfile_fd, STDOUT);
	close(fd[PIPE_IN]);
	close(fd[PIPE_OUT]);
	char *command = check_executable("/grep", envp);
	return (execve(command, argv, NULL));
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
	int 	fd[4] = {5, 6, 7, 8}; //임의의 값을 넣고 있는데 사용하지 않는 포트를 어떻게 받을 것인가?
	pid_t	pid;
	int		file_fd[2];
	int		i;

	int status;

	//infile[0], outfile[1] fd open 
	init_file_fd(av, ac, *file_fd);
	//STD in/out backup
	dup2(STDIN, fd[STDIN_COPY]);
	dup2(STDOUT, fd[STDOUT_COPY]);
	//stdin이 infile 가르킴 : infile을 stdin으로 받음
	dup2(file_fd[0], STDIN);
	close(file_fd[0]);
	//fd를 pipe[0][1]로 만듬 
	if (pipe(fd) == -1)
		return (printf("pipe error\n"));
	// pipecheck(fd, "parent\n");
	i = 1;
	while (i < ac)
	{
		pid = fork();
		if (pid == -1)
			return (printf("forkrerror\n"));
		else if (pid == 0)
		{
			// pipecheck(fd , "child\n");
			return (childproc(fd, file_fd[1], envp));
		}
		waitpid(pid, &status, 0);

	}
	close(fd[PIPE_OUT]);
	close(fd[PIPE_IN]);
	write(fd[STDOUT_COPY], "finished\n", 10);
	return (0);
}

//infile, outfile 확인 및 fd 반환
void *init_file_fd(int ac, char **av, int file_fd[])
{
	if (ac < 3 || access(av[1], F_OK | X_OK) == -1)
		call_exit(1);
	file_fd[0] = open("infile", O_RDONLY);
	if (file_fd[0] < 0)
		call_exit(1);
	file_fd[1] = open("outfile", O_WRONLY | O_TRUNC | O_CREAT | 0644);
	if (file_fd[1] < 0)
	{
		close(file_fd[0]);
		call_exit(0);
	}
}

int call_exit(int i)
{
	exit(i);
}