/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/07 21:44:52 by siwolee          ###   ########.fr       */
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

char	*read_line(t_list *node)
{
	int		read_num;
	char	*line = 0;
	int		len;

	read_num = BUFFER_SIZE;
	while (read_num == BUFFER_SIZE)
	{
		if (*node->buf == 0)
			read_num = read(node->fd, node->buf, BUFFER_SIZE);
		if (read_num < 0)
			return (0);
		if (read_num == 0)
			break;
		len = chk_buf_n(node->buf, '\n') + 1;
		line = realloc_line(line, node, len);
		if (!line)
			return (0);
		if (node->idx == 1)
			return (line);
	}
	node->buf = ft_free(node->buf);
	return (line);
}



// char	*next_line(t_list *node)
// {
// 	int		read_num;
// 	char	*line;

// 	read_num = BUFFER_SIZE;
// 	line = NULL;
// 	while (read_num == BUFFER_SIZE)
// 	{
// 		if (*node->buf == 0)
// 			read_num = read(node->fd, node->buf, BUFFER_SIZE);
// 		if (read_num < 1)
// 		{
// 			node->flag = 0;
// 			return (line);
// 		}
// 		line = realloc_line(line, node->buf, chk_buf_n(node->buf, '\n') + 1);
// 		node->buf = trim_buf(node->buf, '\n');
// 		if (!line || !node->buf)
// 			return (NULL);
// 		if (line[ft_strlen(line) - 1] == '\n')
// 			return (line);
// 	}
// 	node->flag = 0;
// 	return (line);
// }

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
	if (s[0] == 0)
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

char	*ft_strdup(const char *s, int idx)
{
	int		i;
	char	*dest;
	int		len;

	len = ft_strlen(s);
	while (i )
	
}

char	*realloc_line(char *line, t_list *node, size_t len)
{
	char	 *res;
	size_t	l_len;

	if (!node->buf || !len)
		return (line);
	if (!line)
		res = ft_calloc(len);
	else
	{
		l_len = ft_strlen(line);
		res = ft_calloc(len + l_len);
		l_len = ft_strncat(res, line, l_len + 1);
		line = ft_free(line);
	}
	if (!res)
		return (0);
	ft_strncat(res, node->buf, l_len + len + 1);
	node->buf = ft_strtrim(node->buf, len);
	if (res[l_len - 1] == '\n')
		node->idx = 1;
	return (res);
}

char	*ft_strtrim(char *buf, size_t len)
{
	char	*newbuf;

	if (*buf == 0)
	{
		ft_calloc((size_t)BUFFER_SIZE + 1)
		return (buf);
	}
	newbuf = ft_dup(buf + len);
	ft_free(buf);
	return (newbuf);
}


// char	*trim_buf(char *buf, char n)
// {
// 	int		len;
// 	char	*res;
// 	int		i;
// 	//int		flag;

// 	i = 0;
// 	if (!buf)
// 	{
// 		free(buf);
// 		res = malloc(1);
// 		*res = 0;
// 		return (res);
// 	}
// 	while (buf[i] && buf[i] != n)
// 		i++;

// 		len = ft_strlen(buf + i) + 1;
// 		res = (char *)malloc(len);
// 		if (!res)
// 			return (0);
// 		ft_strncat(res, buf + 1 + i, len);
// 		free(buf);
// 		return (res);
// 	return (buf);
// }

int	chk_buf_n(char *buf, char n)
{
	int i;

	i = 0;
	while (buf[i] && buf[i] != n)
		i++;
	return (i);
}
