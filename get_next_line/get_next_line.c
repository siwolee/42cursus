/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haecho <haecho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:24 by haecho            #+#    #+#             */
/*   Updated: 2022/11/23 12:40:54 by haecho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_head	**hhead = 0;
	t_node			*node;
	char			*line;
	int				res;

	node = chk_head(hhead, fd);
	if (!node)
		return (0);
	res = find_newline(hhead, &node, fd, &line);//p_num, 현재 숫자 이후에 라인이 있으면 반환하고 1 추가
	if (res == 1)
		return (line);
	else // free 끝난 상태. 
		return (0);
}