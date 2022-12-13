/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/08 23:57:03 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	chk_n_idx(char *buf)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	strsize;

	strsize = ft_strlen(s);
	if (len + start > strsize && start <= strsize)
		len = strsize - start;
	if (strsize == 0 || start >= strsize)
	{
		ptr = (char *)ft_calloc(1, 1);
		if (!ptr)
			return (0);
		return (ptr);
	}
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	ft_strncat(ptr, s + start, len + 1);
	return (ptr);
}

char	*read_line(char **buf, int fd)
{
	int		read_num;
	char	*line;

	line = NULL;
	if (!(*buf))
		return (line);
	read_num = 1;
	while (read_num > 0)
	{
		line = new_line(buf, line);
		if (chk_n_idx(line) >= 0)
			return (line);
		if (!ft_strlen(*buf))
			read_num = read(fd, *buf, (size_t)BUFFER_SIZE);
		if (read_num == -1 || (!read_num && ft_strlen(line) == 0))
		{
			free(line);
			line = 0;
		}
	}
	free(*buf);
	*buf = NULL;
	return (line);
}

char	*new_line(char **buf, char *line)
{
	size_t	b_idx;
	size_t	l_idx;
	char	*newline;

	if (!*buf)
		return (line);
	b_idx = 0;
	while ((*buf)[b_idx] && (*buf)[b_idx] != '\n')
		b_idx++;
	if ((*buf)[b_idx] == '\n')
		b_idx++;
	l_idx = 0;
	while (line && line[l_idx])
		l_idx++;
	newline = ft_calloc(b_idx + l_idx + 1, sizeof(char));
	if (!newline)
		return (0);
	ft_strncat(newline, line, l_idx + 1);
	ft_strncat(newline, *buf, b_idx + 1);
	free(line);
	*buf = split_buf(buf, b_idx);
	return (newline);
}

char	*split_buf(char **buf, size_t b_idx)
{
	char	*newbuf;

	if ((*buf)[b_idx] == 0)
	{
		newbuf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	}
	else
	{
		newbuf = ft_substr(*buf, b_idx, BUFFER_SIZE);
	}
	free(*buf);
	return (newbuf);
}
