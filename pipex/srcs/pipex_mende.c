/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mende.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/02/23 17:02:56 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>


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
	wait_all_child(i - 1);
	wait(&status);
	waitpid(pid, &status, 0);
	free(path);
}
