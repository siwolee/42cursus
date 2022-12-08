/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/08 18:39:16 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(void *ptr)
{
	free(ptr);
	return (0);
}

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
	return (0);
}

char	*read_line(char **buf, int fd)
{
	int		read_num;
	char	*line;

	line = NULL;
	if (!*buf)
		return (line);
	while (read_num > 0)
	{
		line = new_line(buf, line);
		if (chk_n_idx(line))
			return (line);
		if (line != NULL && *line == 0)
			return (ft_free(line));
		if (!chk_n_idx(*buf))
			read_num = read(fd, *buf, BUFFER_SIZE);
	}
	*buf = ft_free(*buf);
	if (read_num == -1)
		return (ft_free(line));
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
	ft_strlcat(newline, line, l_idx + 1);
	ft_strlcat(newline, *buf, b_idx + 1);
	*buf = split_buf(buf, b_idx);
	return (newline);
}

char	*split_buf(char **buf, size_t b_idx)
{
	char	*newbuf;

	if (!(*buf)[b_idx])
		ft_bzero(*buf, BUFFER_SIZE);
	else
	{
		newbuf = ft_substr(*buf, b_idx, BUFFER_SIZE);
		ft_free(*buf);
		*buf = newbuf;
	}
	return (*buf);
}