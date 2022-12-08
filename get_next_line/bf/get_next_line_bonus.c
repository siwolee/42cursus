/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/07 00:47:38 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	**head;
	t_list			*node;
	char			*line;
	int				flag;

	if (!head)
	{
		head = (t_list **)malloc(sizeof(t_list *));
		node = new_node(fd);
		*head= node;
	}
	node = chk_node(head, fd);
	if (!node || !head)
		return (0);
	flag = 1;
	line = next_line(head, node, &flag);
	if (!*head && flag == 0)
		free(head);
	return (line);
}