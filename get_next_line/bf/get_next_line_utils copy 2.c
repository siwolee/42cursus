/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/07 14:46:17 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*new_node(int fd)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (0);
	head->fd = fd;
	head->next = 0;
	head->flag = 1;
	head->buf = (char *)malloc(sizeof (char) * BUFFER_SIZE);
	if (!head->buf)
	{
		free(head);
		return (0);
	}
	head->buf[0] = 0;
	return (head);
}

char	*next_line(t_list *node)
{
	int		read_num;
	char	*line;

	read_num = BUFFER_SIZE;
	line = NULL;
	while (read_num == BUFFER_SIZE)
	{
		if (*node->buf == 0)
			read_num = read(node->fd, node->buf, BUFFER_SIZE);
		if (read_num < 1)
		{
			node->flag = 0;
			return (line);
		}
		line = realloc_line(line, node->buf, chk_buf_n(node->buf, '\n') + 1);
		node->buf = trim_buf(node->buf, '\n');
		if (!line || !node->buf)
			return (NULL);
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	node->flag = 0;
	return (line);
}
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	idx;

	if (!src)
		return (0);
	d_len = 0;
	s_len = 0;
	idx = -1;
	while (dst[d_len])
		d_len++;
	while (src[s_len])
		s_len++;
	if (d_len >= dstsize)
		return (s_len + dstsize);
	if (dstsize == 0)
		return (s_len);
	while (src[++idx] && idx + d_len < dstsize - 1)
		dst[d_len + idx] = src[idx];
	dst[d_len + idx] = 0;
	return (d_len + s_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (s[0] == 0)
		return (0);
	while (s && s[size])
		size++;
	return (size);
}

char	*realloc_line(char *line, char *buf, size_t len)
{
	char	 *res;
	size_t	l_len;

	if (!buf || !len)
		return (line);
	if (!line)
		res = (char *)malloc(len);
	else
	{
		l_len = ft_strlen(line);
		res = (char *)malloc(len + l_len);
		ft_strlcat(res, line, l_len + 1);
		free(line);
	}
	if (!res)
		return (0);
	ft_strlcat(res, buf, l_len + len + 1);
	return (res);
}


char	*trim_buf(char *buf, char n)
{
	int		len;
	char	*res;
	int		i;
	//int		flag;

	i = 0;
	if (!buf)
	{
		free(buf);
		res = malloc(1);
		*res = 0;
		return (res);
	}
	while (buf[i] && buf[i] != n)
		i++;

		len = ft_strlen(buf + i);
		res = (char *)malloc(len);
		if (!res)
			return (0);
		ft_strlcat(res, buf + 1 + i, len);
		free(buf);
		return (res);
	return (buf);
}

int	chk_buf_n(char *buf, char n)
{
	int i;

	i = 0;
	while (buf[i] && buf[i] != n)
		i++;
	return (i);
}
