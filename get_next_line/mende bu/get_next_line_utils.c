/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/14 12:24:42 by siwolee          ###   ########.fr       */
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

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	n;
	size_t	i;

	n = count * size;
	ptr = (char *)malloc(n);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strsize_n(const char *s, char n)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	if (n == 0)
	{
		while (s[size])
			size++;
	}
	else
	{
		while (s[size] && s[size] != n)
			size++;
		if (s[size] == n)
			size++;
	}
	return (size);
}

char	*read_line(t_list **lst)
{
	int		read_num;
	char	*line;
	// size_t	b_idx;

	line = NULL;
	if (!(*lst)->buf)
		return (line);
	read_num = 1;
	while (read_num > 0)
	{
		// b_idx = new_line(lst, line);
		if (new_line(lst, &line) > 0)
			return (line);
		if ((!((*lst)->buf) || !((*lst)->buf)[0]))
			read_num = read((*lst)->fd, (*lst)->buf, (size_t)BUFFER_SIZE);
		if (read_num == -1 || (!read_num && (!line || !line[0])))
		{
			free(line);
			line = 0;
		}
	}
	free((*lst)->buf);
	(*lst)->buf = NULL;
	return (line);
}

int	new_line(t_list **list, char **line)
{
	size_t	b_idx;
	size_t	l_idx;
	char	*newline;
	t_list	*lst;

	lst = *list;
	if (!lst->buf)
	{
		return (0);
	}
	b_idx = ft_strsize_n(lst->buf, '\n');
	l_idx = ft_strsize_n(*line, 0);
	newline = ft_calloc(b_idx + l_idx + 1, sizeof(char));
	if (!newline)
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	ft_strncat(newline, *line, l_idx + 1);
	ft_strncat(newline, lst->buf, b_idx + 1);
	free(*line);
	lst->buf = split_buf(lst, b_idx);
	if (lst->buf == NULL)
	{
		free(newline);
		*line = NULL;
		return (0);
	}
	*line = newline;
	if (newline[b_idx + l_idx - 1] == '\n')
		return (1);
	return (0);
}

char	*split_buf(t_list *lst, size_t b_idx)
{
	char	*newbuf;
	size_t	len;

	newbuf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (newbuf == NULL)
		return (0);
	len = 0;
	if (lst->buf[b_idx] != 0)
	{
		while (lst->buf[b_idx + len] != 0)
			len++;
		ft_strncat(newbuf, &(lst->buf[b_idx]), len + 1);
	}
	free(lst->buf);
	return (newbuf);
}
