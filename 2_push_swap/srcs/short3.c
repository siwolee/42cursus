/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:09:30 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/16 22:32:00 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *s, char ab)
{
	t_node *a;

	if (ab == ABOT)
		execute(s, "777");
	if (ab == BBOT)
		execute(s, "888");
	if (ab == ATOP || ab == ABOT)
	{
		a = s->atop;
		ab = ATOP;
	}
	else
	{
		a = s->btop;
		ab = BTOP;
	}
	return (sort_three_ab(s, a, ab));
}

void	sort_three_ab(t_stack *s, t_node *a, char ab)
{
	unsigned int	val;

	if (a->val > a->next->val)
	{
		if (a->val > a->next->next->val)
			val = 1;
		else
			val = 3;
	}
	else
	{
		if (a->next->val > a->next->next->val)
			val = 2;
		else
			val = 3;
	}
	if (ab == ATOP)
		sort_three_atop(s, val);
	else
		sort_three_btop(s, val);
}

void	sort_three_atop(t_stack *s, unsigned int a)
{
	if (s->asize == 3)
	{
		if (a == 1)
			ra(s);
		if (a == 2)
			rra(s);
	}
	else
	{
		if (a == 1)
			sa(s);
		if (a <= 2)
		{
			pb(s);
			sa(s);
			pa(s);
		}
	}
	if (s->atop->val > s->atop->next->val)
		sa(s);
}

void	sort_three_btop(t_stack *s, unsigned int a)
{
	if (s->bsize == 3 && a == 3)
			rrb(s);
	else if (a == 2 || (a == 3 && s->btop->val < s->btop->next->val))
		sb(s);
	pa(s);
	if (s->btop->val < s->btop->next->val)
		sb(s);
	pa(s);
	if (s->atop->val > s->atop->next->val)
		sa(s);
	pa(s);
}
