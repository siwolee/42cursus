/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/14 00:32:44 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = 0;
	if (!lst)
		lst = init_list(fd);
	if (!lst)
		return (NULL);
	line = read_line(&lst);
	if (line == NULL)
	{
		free(lst->buf);
		lst->buf = NULL;
		free(lst);
		lst = NULL;
	}
	return (line);
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

t_list	*init_list(int fd)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->fd = fd;
	lst->next = 0;
	lst->buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (lst->buf == NULL)
	{
		free(lst);
		return (0);
	}
	return (lst);
}
