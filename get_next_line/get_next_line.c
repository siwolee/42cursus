/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:24 by haecho            #+#    #+#             */
/*   Updated: 2022/12/06 17:27:23 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_head	**hhead;
	t_node			*node;
	char			*line;
	int				res;

	head = chk_head(hhead, fd);
	if (!head)
	{
		free_all(hhead);
		return (0);
	}
	node = find_newline(hhead, &node, fd, &line);//p_num, 현재 숫자 이후에 라인이 있으면 반환하고 1 추가
	if (!node)
		free_all(hhead);
	if (node->num == 1)
	{
		node->num = 0;
		return (res);
	}
	if (node->num == -1)
		free_head(head);
	if (!*hhead)
		free_all(hhead);
	return (0);
}