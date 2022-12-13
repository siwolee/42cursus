/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/09 18:01:01 by siwolee          ###   ########.fr       */
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
	line = read_line(&lst);
	if (line == NULL)
	{
		free(lst);
		lst = NULL;
	}
	return (line);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	size;

// 	size = 0;
// 	while (s && s[size])
// 		size++;
// 	return (size);
// }

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
	lst->buf = ft_calloc((size_t)BUFFER_SIZE, sizeof(char));
	if (!lst->buf)
	{
		free(lst);
		return (0);
	}
	return (lst);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	n;
	size_t	i;

	n = count * size;
	ptr = (char *)malloc(n);
	if (!ptr)
		return (0);
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
