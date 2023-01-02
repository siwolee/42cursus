/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:32:05 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/02 17:17:33 by siwolee          ###   ########.fr       */
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
		if (node->val > node->next->val)
			execute(s, 0, -1);
	}
	else if (s->abot == node)
	{
		if (node->val > node->next->val)
			execute(s, 0, -1);
	}
}