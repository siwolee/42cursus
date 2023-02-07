/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mendatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/02/02 23:59:49 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

char *check_executable(char *cmd, char *const *envp);

int main(int ac, char **av, char **envp)
{
	int 	fd[2];
	pid_t	pid;
	int		infile_fd;
	int		outfile_fd;
	int		i;
	int 	status;


	infile_fd = open("infile", O_RDONLY);
	//stdin이 infile 가르킴 : infile을 stdin으로 받음
	dup2(infile_fd, fd[0]);
	dup2(fd[1], STDIN);
	close(infile_fd);
	if (pipe(fd) == -1)
		return (printf("pipe error\n"));
	i = 2;
	while (i < ac - 1)
	{
		char **argv = ft_split(av[i], ' ');
		char *command = check_executable(*argv, envp);
		pid = fork();
		if (pid == -1)
			return (printf("forkrerror\n"));
		//프로세스에서는 파이프에 한 번에 읽기 혹은 쓰기밖에 못함.
		else if (pid == 0)
		{
			//stdin에는 이미 infile이 들어가 있음
			// dup2(infile_fd, fd[0]);
			//stdout이 1을 가르킴 : 스탠다드아웃을 파이프아웃으로 보냄
			close(fd[0]);
			// close(outfile_fd);
			dup2(fd[1], STDOUT);
			return (execve(command, argv, NULL));
		}
		i++;
	}
	waitpid(pid, &status, 0);
	//pipe out 닫음 > 그래야 read 가능
	outfile_fd = open("outfile", O_WRONLY | O_TRUNC | O_CREAT | 0644);
	close(fd[1]);
	char *buf;
	while ((buf = get_next_line(fd[0])))
	{
		ft_putstr_fd(buf, outfile_fd);
		free(buf);
	}
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
// char *check_executable(char *cmd, char *const *envp)
// {
// 	int i = 0;
// 	char **path;
// 	char *testcmd;
	
// 	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
// 	{
// 		i++;
// 	}
// 	path = ft_split(envp[i] + 5, ':');

// 	i = 0;
// 	while (path[i])
// 	{
// 		testcmd = ft_strjoin(path[i], cmd);
// 		if (access(testcmd, F_OK | X_OK) != -1)
// 			break;
// 		free(testcmd);
// 		testcmd = 0;
// 		i++;
// 	}
// 	return (testcmd);
// }