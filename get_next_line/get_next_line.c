/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/08 21:55:13 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = 0;
	if (!buf)
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (0);
	line = read_line(&buf, fd);
	return (line);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s && s[size])
		size++;
	return (size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	idx;

	d_len = 0;
	s_len = 0;
	idx = -1;
	if (!src)
		return (0);
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

void	ft_bzero(void *s, size_t n)
{
	while (n)
	{
		*(char *)s = 0;
		n--;
		s++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

