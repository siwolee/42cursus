/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:12:04 by siwolee           #+#    #+#             */
/*   Updated: 2023/02/23 16:31:00 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/include/libft.h"

#define IN_A 0
#define OUT_A 1
#define IN_B 2
#define OUT_B 3
#define INFILE 4
#define OUTFILE 5

#define BUFFER_SIZE 20

int	child_proc(int fd_in, int fd_out, char **path, char **cmd);

int	fd_in(int i, int *fd);
int	fd_out(int i, int *fd, int ac);
void	fd_close(int i, int *fd, int ac);
void	fd_reopen(int i, int *fd, int ac);
char	**get_path(char *const *envp);
char	*check_executable(char *cmd, char **path);
char	**init_check(int ac, char *const *envp);
int	child_proc(int fd_in, int fd_out, char **path, char **cmd);
void close_all_fd(int *fd, int cnt);
int	*wait_all_child(int child_cnt);

char		*get_next_line(int fd);
int 	pipecheck(int fd[], char *name);
char	*ft_strjoin(char const *s1, char const *s2);



#endif