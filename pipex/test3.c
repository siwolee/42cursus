/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/02/10 11:10:08 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"
#include <errno.h>

#define IN_A 0
#define OUT_A 1
#define IN_B 2
#define OUT_B 3
#define INFILE 4
#define OUTFILE 5

int	fd_in(int i, int *fd)
{
	if (i == 2)
		return (fd[INFILE]);
	if (i % 2 == 0)
		return (fd[IN_B]);
	else
		return (fd[IN_A]);
}

int	fd_out(int i, int *fd, int ac)
{
	if (i == ac - 2 || ac == 4)
		return (fd[OUTFILE]);
	if (i % 2 == 0)
		return (fd[OUT_A]);
	else
		return (fd[OUT_B]);
}

void	fd_close(int i, int *fd, int ac)
{
	if (i == 2)
	{
		close(fd[IN_A]);
		close(fd[IN_B]);
		close(fd[OUT_B]);
		printf("\ni = %d, closed IN_A , B\n", i);
	}
	else if (i == ac - 2 && i % 2)
	{
		close(fd[IN_B]);
		close(fd[OUT_B]);
		close(fd[OUT_A]);
		printf("\ni = %d, closed OUT_A, B\n", i);
	}
	else if (i == ac - 2 && i % 2 == 0)
	{
		close(fd[IN_A]);
		close(fd[OUT_A]);
		close(fd[OUT_B]);
		printf("\ni = %d, closed OUT_B, A\n", i);
	}
	else if (i % 2)
	{
		close(fd[IN_B]);
		close(fd[OUT_A]);
		printf("\ni = %d, closed IN_B, OUT_A\n", i);
	}
	else if (i % 2 == 0)
	{
		close(fd[IN_A]);
		close(fd[OUT_B]);
		printf("\ni = %d, closed IN_A, OUT_B\n", i);
	}
	else
		printf("close error\n");
}
void	fd_reopen(int i, int *fd, int ac)
{
	if (i < 3 || i == ac - 2)
		return ;
	if (i % 2) // reopen B
	{
		close(fd[IN_B]);
		close(fd[OUT_B]);
		pipe(fd + 2);
	}
	else
	{
		close(fd[IN_A]);
		close(fd[OUT_A]);
		pipe(fd);
	}
}

char	**get_path(char *const *envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
	{
		i++;
	}
	return (ft_split_replace(envp[i] + 5, ':', '/'));
}

char	*check_executable(char *cmd, char **path)
{
	int		i;
	char	*testcmd;

	i = 0;
	i = 0;
	testcmd = NULL;
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

char	**init_check(int ac, char *const *envp)
{
	//heredoc 옵션 필요함
	if (ac < 4)
		exit(2);
	return (get_path(envp));
}

int	child_proc(int fd_in, int fd_out, char **path, char **cmd)
{
	printf("print.. in%d out%d %s\n", fd_in, fd_out, *cmd);
	if (dup2(fd_in, STDIN_FILENO) == -1)
		printf("dup in fail\n");
	close(fd_in);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		printf("dup out fail\n");
	close(fd_out);
	execve(check_executable(*cmd, path), cmd, NULL);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[6];
	pid_t	pid;
	int		i;
	int		status;
	char	**path;

	path = init_check(ac, envp);
	printf("ac : %d\n", ac);
	pipe(fd);
	pipe(fd + 2);
	fd[INFILE] = open(av[1], O_RDONLY);
	fd[OUTFILE] = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd[INFILE] == -1 || fd[OUTFILE] == -1)
		printf("errno : %d\n", errno);
	i = 1;
	while (++i < ac - 1)
	{
		fd_reopen(i, fd, ac);
		pid = fork();
		if (pid == 0)
		{
			fd_close(i, fd, ac);
			child_proc(fd_in(i, fd), fd_out(i, fd, ac), \
						path, ft_split(av[i],' '));
		}
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	close(fd[4]);
	close(fd[5]);
	waitpid(pid, &status, 0);
	free(path);
}
