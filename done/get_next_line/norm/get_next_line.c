/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/21 14:57:29 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	lst;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = read_line(lst.buf, fd);
	return (line);
}

char	*read_line(char buf[], int fd)
{
	int		read_num;
	char	*line;

	line = NULL;
	read_num = 1;
	while (read_num > 0)
	{
		line = new_line(buf, line);
		if (chk_n_idx(line, '\n') >= 0)
			return (line);
		if (!chk_n_idx(buf, 0))
			read_num = read(fd, buf, (size_t)BUFFER_SIZE);
		if (read_num == -1 || (!read_num && chk_n_idx(line, 0) == 0))
		{
			free(line);
			line = 0;
		}
	}
	return (line);
}

char	*new_line(char buf[], char *line)
{
	size_t	b_idx;
	size_t	l_idx;
	char	*newline;

	b_idx = 0;
	while ((buf)[b_idx] && (buf)[b_idx] != '\n')
		b_idx++;
	if ((buf)[b_idx] == '\n')
		b_idx++;
	l_idx = 0;
	while (line && line[l_idx])
		l_idx++;
	newline = ft_calloc(b_idx + l_idx + 1, sizeof(char));
	if (!newline)
	{
		free(line);
		return (0);
	}
	ft_strncat(newline, line, l_idx + 1);
	ft_strncat(newline, buf, b_idx + 1);
	free(line);
	split_buf(buf, b_idx);
	return (newline);
}

char	*split_buf(char buf[], size_t b_idx)
{
	int	n;

	n = 0;
	if (buf[b_idx] != 0)
	{
		n = 0;
		while (buf[b_idx] != 0)
		{
			buf[n] = buf[b_idx];
			n++;
			b_idx++;
		}
	}
	while (n < BUFFER_SIZE)
	{
		buf[n] = 0;
		n++;
	}
	return (buf);
}

size_t	ft_strncat(char *dst, const char *src, size_t srcsize)
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
	while (src[++idx] && idx < srcsize - 1)
		dst[d_len + idx] = src[idx];
	dst[d_len + idx] = 0;
	return (d_len + s_len);
}
