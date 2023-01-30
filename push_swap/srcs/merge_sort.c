/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:28:30 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 21:14:44 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_merge_mostbig(t_stack *s, char ab)
{
	if (ab == ATOP)
		ra(s);
	else if (ab == ABOT)
	{
		rra(s);
	}
	else if (ab == BTOP)
		pa(s);
	else
	{
		rrb(s);
		pa(s);
	}
}

void	sort_merge_big(t_stack *s, char ab)
{
	if (ab == ATOP)
	{
		pb(s);
		if (s->btop->next && (s->btop->val < s->btop->next->val))
			sb(s);
	}
	else if (ab == ABOT)
	{
		rra(s);
		pb(s);
	}
	else if (ab == BTOP)
	{
		pa(s);
		ra(s);
	}
	else
		rrb(s);
}

void	sort_merge_small(t_stack *s, char ab)
{
	if (ab == ATOP)
	{
		pb(s);
		rb(s);
	}
	else if (ab == ABOT)
	{
		rra(s);
		pb(s);
		rb(s);
	}
	else if (ab == BTOP)
	{
		rb(s);
	}
	else
	{
		rrb(s);
		pa(s);
		ra(s);
	}
}
