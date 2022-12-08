/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/07 23:25:14 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n)
	{
		*(char *)s = 0;
		n--;
		s++;
	}
}

char	*ft_calloc(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(size);
	if (!ptr)
		return (0);
	i = -1;
	while (++i < size)
		ptr[i] = 0;
	return (ptr);
}
size_t	ft_strncat(char *dst, const char *src, size_t len)
{
	size_t	d_len;
	size_t	idx;

	if (!src)
		return (0);
	d_len = 0;
	idx = -1;
	while (dst[d_len])
		d_len++;
	if (len == 0)
		return (d_len);
	while (src[++idx] && idx < len - 1)
		dst[d_len + idx] = src[idx];
	dst[d_len + idx] = 0;
	return (d_len + len);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (s && s[size])
		size++;
	return (size);
}

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (0);
}

int	chk_buf_n(char *buf)
{
	size_t i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i);
	return (0);
}

char	*read_line(t_list *node, char *buf, char *line)
{
	int		read_num;
	char	*buf;

	if (!node->buf)
		return (0);
	read_num = 1;
	buf = node->buf + ft_strlen(node->buf);
	while (1)
	{
		while (!chk_buf_n(node->buf) && buf < node->buf + 1024 && read_num > 0)
		{
			read_num = read(node->fd, buf, (size_t)BUFFER_SIZE);
			buf += read_num;
		}
		if (read_num == -1)
			return (0);
		line = seperate_line(node, line);
		if (read_num == 0)
			node->idx = -1;
		if (node->idx == 1 || node->idx == -1)
			return (line);
	}
}

char	*seperate_line(t_list *node, char *line)
{
	int		len;
	int		buflen;
	char	*newline;

	len = ft_strlen(line);
	buflen = chk_buf_n(node->buf);
	if (!buflen)
	{
		buflen = ft_strlen(node->buf);
		node->idx = 0;
	}
	else
		node->idx = 1;
	newline = ft_calloc(len + buflen + 1);
	if (line)
	{
		ft_strncat(newline, line, len + 1);
		ft_free(line);
	}
	ft_strncat(newline, node->buf, buflen);
	node->buf = seperate_buf(node);
	return (newline);
}

char	*seperate_buf(t_list *node)
{
	int		n;
	int		len;
	char	*newbuf;

	newbuf = ft_calloc(1024);
	if (node->idx == 0)
	{
		node->buf = ft_free(node->buf);
		return (newbuf);
	}
	n = 0;
	len = 0;
	while (node->buf[n] != '\n')
		n++;
	while (node->buf[n + len] != 0)
		len++;
	if (!newbuf)
		return (0);
	ft_strncat(newbuf, node->buf + n + 1, len + 1);
	return (newbuf);
}
