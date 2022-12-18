/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/17 23:28:25 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
	{
		return (NULL);
	}
	if (!lst)
	{
		lst = malloc(sizeof(t_list));
		lst->fd = fd;
		lst->buf[0] = 0;
		lst->idx = 0;
	}
	line = read_line(0, fd, lst->buf, &lst->idx);
	cut_buf(lst->buf, &lst->idx);
	if (line == NULL)
		free(lst);
	return (line);
}

char	*read_line(int len, int fd, char buf[], int *idx)
{
	char	*line;
	int		read_len;
	int		n;

	line = NULL;
	read_len = BUFFER_SIZE;
	if (*idx == 0)
		read_len = read(fd, buf, BUFFER_SIZE);
	if (read_len < 0)
		return (NULL);
	n = chk_n_idx(buf, '\n');
	if (n >= 0 || read_len + 1 < BUFFER_SIZE || buf[*idx] == 0)
	{
		if (n < 0)
			n = read_len;
		line = malloc(len + n + 2);
	}
	else
	{
		line = read_line(len + BUFFER_SIZE, fd, buf, idx);
		n = BUFFER_SIZE;
	}
	if (line)
		n_cpy(line + len, buf, n);
	return (line);
}

int n_cpy(char *dst, char *src, int n)
{
	int	i;

	if (!dst)
		return (0);
	i = 0;
	while (i <= n && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dst[i] == '\n')
		dst[i + 1] = 0;
	return (i);
}

int	chk_n_idx(char *buf, char n)
{
	int	i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf[i] && buf[i] != n)
		i++;
	if (buf[i] == n)
		return (i);
	return (-1);
}

void	cut_buf(char buf[], int *idx)
{
	int	n;

	n = chk_n_idx(buf, '\n');
	if (n >= 0)
	{
		*idx = n_cpy(buf,buf + n + 1, BUFFER_SIZE - n - 1);
	}
	else
		*idx = 0;
	buf[*idx] = 0;
}