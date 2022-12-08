/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:34 by haecho            #+#    #+#             */
/*   Updated: 2022/12/06 18:39:29 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

typedef struct	s_node
{
	char			*line;
	int			num; // 마지막 eof 감지시 -1, 내보냄 0, 안내보냄 1. 미완 2. 첫 라인 초기화를 뭘로 해야 할까?
	struct s_node	*next;
}	t_node;

typedef struct	s_head
{
	ssize_t			fd;
	struct s_head	*next;
	struct s_node	*node;
}	t_head;

char	*get_next_line(int fd);

t_node	*init_node();
t_head	**init_head(int fd);
void	*new_head(t_head *head, int fd);
t_head	*get_head(t_head *head, int fd);
t_head	*chk_head(t_head **hhead, int fd);
t_node	*last_unout_node(t_head *head);
t_node	*last_node(t_node *node);
t_node	*chk_line(t_head *head);
char	*ft_strndup(char *dst, char *src, int len);
t_node	*read_line(t_node *node, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char 	*ft_calloc(size_t bufsize);
size_t	ft_strlen(const char *s);
void	realloc_line(t_node *node, char *buf, size_t bufsize);
int		chk_buf_n(char *buf, char n);
int		new_node(t_node *node, char *buf);
void	free_all(t_head **hhead);
void	free_head(t_head **hhead, t_head *head);


#endif