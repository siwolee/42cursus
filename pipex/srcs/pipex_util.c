/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/02/23 18:55:13 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

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
		close(fd[IN_B]);
	else if (i == ac - 2)
	{
		close(fd[OUT_B]);
		close(fd[OUT_A]);
	}
	if (i % 2)
	{
		close(fd[IN_B]);
		close(fd[OUT_A]);
	}
	else if (i % 2 == 0)
	{
		close(fd[IN_A]);
		close(fd[OUT_B]);
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

void close_all_fd(int *fd, int cnt)
{
	int i;

	i = 0;
	while (i < cnt)
	{
		if (fd[i] > 0)
			close(fd[i]);
		i++;
	}
}

int	wait_all_child(int child_cnt, pid_t pid)
{
	int *status;

	status = NULL;
	while (--child_cnt > 1)
	{
		wait(status);
	}
	waitpid(pid, *status, 0);
	return (status);
}

int check_infile(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		printf("no such file or directory: %s\n", file);
	return (fd);
}

int check_outfile(char *file)
{
	int fd;

	fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		printf("no such file or directory: %s\n", file);
		exit(1);
	}
	return (fd);
}