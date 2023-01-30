/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:12:04 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/29 18:46:22 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
// #include "./get_next_line_bonus.h"

#define FD_RD 0
#define FD_WR 1
#define FD_OUT 2
#define FD_IN 3

// #define BUFFER_SIZE 20

char		*get_next_line(int fd);
int 	pipecheck(int fd[], char *name);
char	*ft_strjoin(char const *s1, char const *s2);

#endif