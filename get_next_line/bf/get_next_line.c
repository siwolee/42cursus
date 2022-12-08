/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:24 by haecho            #+#    #+#             */
/*   Updated: 2022/12/06 18:42:22 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_head	**hhead;
	t_node			*node;
	t_head			*head;

	if(!hhead)
		hhead = init_head(fd);
	head = chk_head(hhead, fd);
	if (!hhead || !head)
	{
		free_all(hhead);
		return (0);
	}
	node = chk_line(head);//p_num, 현재 숫자 이후에 라인이 있으면 반환하고 1 추가
	if (!node)
	{
		free_all(hhead);
		return (0);
	}	
	if (node->num == 1)
	{
		node->num = 0;
		return (node->line);
	}
	if (node->num == -1)
		free_head(hhead, head);
	if (!*hhead)
		free_all(hhead);
	return (0);
}