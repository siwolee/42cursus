/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/03 15:51:34 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	lst;
	t_list			*fd_lst;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	fd_lst = chk_list(&lst, fd);
	if (fd_lst == 0)
		return (0);
	if (read(fd, NULL, 0) < 0)
	{
		remove_list(&lst, fd_lst);
		return (NULL);
	}
	line = read_line(fd_lst->buf, &fd_lst->fd);
	if (line == NULL || fd_lst->fd == -1)
		fd_lst = remove_list(&lst, fd_lst);
	return (line);
}

t_list	*chk_list(t_list *lst, int fd)
{
	t_list	*temp;

	temp = lst;
	while (temp != 0 && temp->next != 0 && temp->fd != fd)
	{
		temp = temp->next;
	}
	if (temp->fd == fd)
		return (temp);
	temp->next = (t_list *)malloc(sizeof(t_list));
	if (!temp->next)
	{
		lst = lst->next;
		while (lst)
		{
			temp = (lst)->next;
			free((lst));
			lst = temp;
		}
		return (0);
	}
	temp->next->fd = fd;
	(temp->next->buf)[0] = 0;
	temp->next->next = NULL;
	return (temp->next);
}

t_list	*remove_list(t_list *lst, t_list *fd_lst)
{
	while ((lst)->next && (lst)->next != fd_lst)
	{
		lst = (lst)->next;
	}
	if ((lst)->next == fd_lst)
	{
		(lst)->next = fd_lst->next;
		free(fd_lst);
	}
	return (NULL);
}

void	delete_list(t_list *lst)
{
	t_list	*next;
	t_list	*temp;

	temp = lst->next;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
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
