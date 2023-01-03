/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/03 13:00:03 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char buf[], int *fd)
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
		{
			read_num = read(*fd, buf, (size_t)BUFFER_SIZE);
			buf[read_num] = 0;
		}
		if (read_num == -1 || (!read_num && chk_n_idx(line, 0) == 0))
		{
			free(line);
			*fd = -1;
			return (NULL);
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
	while (buf[b_idx] != 0 && (buf)[b_idx] != '\n')
		b_idx++;
	if (buf[b_idx] == '\n')
		b_idx++;
	l_idx = 0;
	while (line && line[l_idx])
		l_idx++;
	newline = ft_calloc(b_idx + l_idx + 1, sizeof(char));
	if (!newline)
	{
		free(line);
		return (NULL);
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

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	n;
	size_t	i;

	n = count * size;
	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

int	chk_n_idx(char buf[], char n)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf[i] && buf[i] != n)
		i++;
	if (buf[i] == n)
		return (i);
	return (-1);
}
