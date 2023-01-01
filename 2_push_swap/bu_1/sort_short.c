/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:32:05 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/01 18:14:00 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_stack *a, t_stack *b, t_node *node)
{
	if (a->top == node)
	{
		if (node->val > node->next->val)
			execute(a, b, 0, -1);
	}
	else if (a->bot == node)
	{
		if (node->val < node->before->val)
			execute(a, b, 4, 4, 0, -1);
		else
			execute(a, b, 4, 4, -1);
	}
}

void	sort_three_123_a(t_stac)