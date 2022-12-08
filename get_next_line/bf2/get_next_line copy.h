/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:34 by haecho            #+#    #+#             */
/*   Updated: 2022/12/07 23:52:30 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifdef BUFFER_SIZE

# else
	#define BUFFER_SIZE 42
# endif
typedef struct	s_list
{
	int		fd;
	char	*buf;
	int		idx;
}	t_list;

char	*ft_calloc(size_t size);
size_t	ft_strncat(char *dst, const char *src, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_free(void *ptr);
void	ft_bzero(void *s, size_t n);
int		chk_buf_n(char *buf);

char	*get_next_line(int fd);
char	*read_line(char *buf, int fd, char *line, int *chk);
char	*seperate_line(char *buf, char *line, int *chk);
char	*seperate_buf(char *buf, int *chk);

#endif