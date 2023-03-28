/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mende.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:43:53 by siwolee           #+#    #+#             */
/*   Updated: 2023/03/01 18:53:10 by siwolee          ###   ########.fr       */
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
	pipe(fd);
	pipe(fd + 2);
	fd[INFILE] = check_infile(av[1]);
	fd[OUTFILE] = check_outfile(av[ac - 1]);
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
	status = wait_all_child(ac - 3, pid);
	free(path);
	return (status);
}
