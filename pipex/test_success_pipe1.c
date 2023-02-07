/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_success_pipe1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/02/02 11:19:59 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

char *check_executable(char *cmd, char *const *envp);


//while 문 안에 넣기 성공
int main(int ac, char **av, char **envp)
{
	int 	fd[2];
	pid_t	pid;
	int		infile_fd;
	int		outfile_fd;

	int status;

	ac = 1;
	av = 0;
	infile_fd = open("infile", O_RDONLY);
	//stdin이 infile 가르킴 : infile을 stdin으로 받음
	dup2(infile_fd, fd[0]);
	dup2(fd[1], STDIN);
	// dup2(infile_fd, STDIN);
	close(infile_fd);
	if (pipe(fd) == -1)
		return (printf("pipe error\n"));
	int i = 2;
	while (i < 3)
	{
		pid = fork();
		if (pid == -1)
			return (printf("forkrerror\n"));
		//프로세스에서는 파이프에 한 번에 읽기 혹은 쓰기밖에 못함.
		else if (pid == 0)
		{
			char *argv[] = {"grep", "a1", NULL};
		
			//stdin에는 이미 infile이 들어가 있음
			// dup2(infile_fd, fd[0]);
			//stdout이 1을 가르킴 : 스탠다드아웃을 파이프아웃으로 보냄
			close(fd[0]);
			// close(outfile_fd);
			dup2(fd[1], STDOUT);
			char *command = check_executable("/grep", envp);
			return (execve(command, argv, NULL));
		}
		i++;
	}
	waitpid(pid, &status, 0);
	//pipe out 닫음 > 그래야 read 가능
	outfile_fd = open("outfile", O_WRONLY | O_TRUNC | O_CREAT | 0644);
	close(fd[1]);
	char buf[20];
	read(fd[0], buf, 20);
	ft_putstr_fd(buf, outfile_fd);
	close(fd[1]);
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