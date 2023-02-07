/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:12:04 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/30 20:00:20 by siwolee          ###   ########.fr       */
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

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define PIPE_IN 0
#define PIPE_OUT 1
#define STDIN_COPY 2
#define STDOUT_COPY 3


// #define BUFFER_SIZE 20

char		*get_next_line(int fd);
int 	pipecheck(int fd[], char *name);
char	*ft_strjoin(char const *s1, char const *s2);

#endif