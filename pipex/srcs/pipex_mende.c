/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mende.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/02/15 19:08:38 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"
#include <errno.h>

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
		else
			printf("pid :: %d\n", pid);

	}
	close_all_fd(fd, 6);
	wait(&status);
	waitpid(pid, &status, 0);
	free(path);
}
