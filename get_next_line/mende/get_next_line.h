/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:34 by haecho            #+#    #+#             */
/*   Updated: 2022/12/17 23:24:23 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifdef BUFFER_SIZE
# else
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	int				idx;
	struct s_list	*next;
}			t_list;

char	*get_next_line(int fd);

char	*read_line(int len, int fd, char buf[], int *idx);
int		n_cpy(char *dst, char *src, int n);
int		chk_n_idx(char *buf, char n);
void	cut_buf(char buf[], int *idx);

#endif