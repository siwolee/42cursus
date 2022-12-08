/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:34 by haecho            #+#    #+#             */
/*   Updated: 2022/12/07 00:43:43 by siwolee          ###   ########.fr       */
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
	int				fd;
	struct s_list	*next;
	char			*buf;
}	t_list;

char	*get_next_line(int fd);
int		chk_buf_n(char *buf, char n);
t_list	*chk_node(t_list **head, int fd);
char	*trim_buf(char *buf, char n);
char	*realloc_line(char *line, char *buf, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
t_list	*new_node(int fd);
void	free_node(t_list **head, t_list *node, int *flag);
char	*next_line(t_list **head, t_list *node, int *flag);

#endif