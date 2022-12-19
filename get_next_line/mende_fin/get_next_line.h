/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:34 by haecho            #+#    #+#             */
/*   Updated: 2022/12/19 16:17:01 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifdef BUFFER_SIZE

# else
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	int		fd;
	char	buf[BUFFER_SIZE + 1];
	int		idx;
}			t_list;

char		*get_next_line(int fd);

char		*read_line(char buf[], int fd);
char		*new_line(char buf[], char *line);
char		*split_buf(char buf[], size_t b_idx);
size_t		ft_strncat(char *dst, const char *src, size_t srcsize);

void		*ft_calloc(size_t count, size_t size);
int			chk_n_idx(char buf[], char n);

#endif