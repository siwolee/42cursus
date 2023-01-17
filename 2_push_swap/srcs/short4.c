/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:58:43 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 21:13:42 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack *s, char ab)
{
	int	val;

	val = get_max_idx(s, ab);
	if (ab & 1 && s->asize == 4)
		return (sort_four_eqaulsize_a(s, val));
	else if (!(ab & 1) && s->bsize == 4)
		return (sort_four_eqaulsize_b(s, val));
	else if (ab == ATOP)
		return (sort_four_atop(s, val));
	else if (ab == BTOP)
		return (sort_four_btop(s, val));
	else if (ab == ABOT)
		return (sort_four_abot(s, val));
	else
		return (sort_four_bbot(s, val));
}

void	sort_four_atop(t_stack *s, unsigned int max_idx)
{
	unsigned int	i;

	i = 0;
	if (max_idx == 3)
		return (sort_three(s, ATOP));
	while (i < 4 && i >= 0)
	{
		if (max_idx == i)
			ra(s);
		else
			pb(s);
		i++;
	}
	rra(s);
	sort_three(s, BTOP);
}

void	sort_four_btop(t_stack *s, unsigned int max_idx)
{
	unsigned int	i;

	i = 0;
	if (max_idx == 0)
	{
		pa(s);
		return (sort_three(s, BTOP));
	}
	while (i < 4 && i >= 0)
	{
		if (max_idx == i)
			pa(s);
		else
			rb(s);
		i++;
	}
	rrb(s);
	rrb(s);
	rrb(s);
	return (sort_three(s, BTOP));
}

void	sort_four_abot(t_stack *s, unsigned int max_idx)
{
	unsigned int	i;

	i = 0;
	if (max_idx == 0)
	{
		rra(s);
		rra(s);
		rra(s);
		rra(s);
		return (sort_three(s, ATOP));
	}
	while (i < 4 && i >= 0)
	{
		rra(s);
		if (max_idx != i)
			pb(s);
		i++;
	}
	sort_three(s, BTOP);
}

void	sort_four_bbot(t_stack *s, unsigned int max_idx)
{
	unsigned int	i;

	i = 0;
	if (max_idx == 0)
	{
		rrb(s);
		pa(s);
		rrb(s);
		rrb(s);
		rrb(s);
		return (sort_three(s, BTOP));
	}
	while (i < 4 && i >= 0)
	{
		rrb(s);
		if (max_idx == i)
			pa(s);
		i++;
	}
	sort_three(s, BTOP);
}
