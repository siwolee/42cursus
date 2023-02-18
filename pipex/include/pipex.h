/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:12:04 by siwolee           #+#    #+#             */
/*   Updated: 2023/02/15 18:15:32 by siwolee          ###   ########.fr       */
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

// #define BUFFER_SIZE 20

char		*get_next_line(int fd);
int 	pipecheck(int fd[], char *name);
char	*ft_strjoin(char const *s1, char const *s2);

#endif