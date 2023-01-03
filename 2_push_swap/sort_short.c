/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:32:05 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/03 16:18:18 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_stack *s, t_node *node)
{
	if (s->atop == node)
	{
		if (node->val > node->next->val)
			execute(s, 0, -1);
	}
	else if (s->abot == node)
	{
		if (node->val < node->before->val)
			execute(s, 4, 4, 0, -1);
		else
			execute(s, 4, 4, -1);
	}
}

void	sort_three_123_a(t_stack *s, t_node *node)

{
	if (s->atop == node)
	{
		return ;
	}
	else if (s->abot == node)
	{
		execute(s, 6, 6, 6, -1);
	}
	else if (s->btop == node)
	{
		execute(s, 5, 1, 2, 2, 7, 2, -1);
	}
	else if (s->bbot == node)
	{
		execute(s, 7, 3, 7, 3, 7, 3, -1);
	}
}