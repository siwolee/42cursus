/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/14 00:26:52 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*fd_lst;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = 0;
	if (!lst)
		lst = init_list(fd);
	fd_lst = chk_list(&lst, fd);
	line = read_line(&fd_lst);
	if (line == NULL)
		fd_lst = remove_list(&lst, fd_lst);
	return (line);
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

t_list	*chk_list(t_list **lst, int fd)
{
	t_list *temp;

	temp = *lst;
	while (temp->next && temp->fd != fd)
	{
		temp = temp->next;
	}
	if (temp->fd == fd)
		return (temp);
	temp->next = init_list(fd);
	if (!temp->next) //말록실패시
	{
		while (lst)
		{
			temp = (*lst)->next;
			free((*lst)->buf);
			free((*lst));
			*lst = temp;
		}
		return (NULL);
	}
	return (temp->next);
}

t_list	*remove_list(t_list **lst, t_list *fd_lst)
{
	if (*lst == fd_lst)
	{
		free((*lst)->buf);
		free(*lst);
		*lst = NULL;
		return (NULL);
	}
	while ((*lst)->next && (*lst)->next != fd_lst)
	{
		*lst = (*lst)->next;
	}
	if ((*lst)->next == fd_lst)
	{
		(*lst)->next = fd_lst->next;
	}
	free(fd_lst->buf);
	free(fd_lst);
	return (NULL);
}
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
