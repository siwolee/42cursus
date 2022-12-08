/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/08 17:37:13 by siwolee          ###   ########.fr       */
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

char	*ft_strncpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < size)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
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
		return (i + 1);
	return (0);
}

char	*read_line(char **buf, int fd, char *line, int *chk)
{
	int		read_num;

	if (!*buf)
		return (0);

	read_num = 1;
	while (read_num > 0)
	{
		line = seperate_line(*buf, line, chk);
		if (chk_buf_n(line))
			return (line);
		if (!chk_buf_n(*buf))
			read_num = read(fd, *buf, (size_t)BUFFER_SIZE);
	}
	*buf = ft_free(*buf);
	if (read_num == -1)
		return (ft_free(line));
	return (line);
}

char	*seperate_line(char *buf, char *line, int *chk)
{
	int		len;
	int		buflen;
	char	*newline;

	len = ft_strlen(line);
	buflen = chk_buf_n(buf);
	if (!buflen) // doesn't return with newline
	{
		buflen = ft_strlen(buf);
		*chk = 0;
	}
	else
		*chk = 1;
	newline = ft_calloc(len + buflen + 1);
	if (!newline)
		return (0);
	if (line)
	{
		ft_strncat(newline, line, len + 1);
		ft_free(line);
	}
	ft_strncat(newline, buf, buflen + 1);
	buf = seperate_buf(buf);
	return (newline);
}

char	*seperate_buf(char *buf)
{
	char	*newbuf;
	int		buflen;

	buflen = chk_buf_n(buf);
	if (!buflen)
	{
		ft_bzero(buf, BUFFER_SIZE);
		return (buf);
	}
	newbuf = buf + buflen;
	ft_strncpy(buf, newbuf, BUFFER_SIZE);
	return (buf);
}
