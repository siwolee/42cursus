/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:58:43 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/16 13:49:22 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four(t_stack *s, char ab)
{
	unsigned int	val[4];

	get_max_idx(s, val, ab);
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

void	sort_four_atop(t_stack *s, unsigned int val[])
{
	unsigned int	i;

	i = 0;
	if (val[0] == 3)
		return (sort_three_atop(s, val[1]));
	while (i < 4 && i >= 0)
	{
		if (val[0] == i)
			ra(s);
		else
			pb(s);
		i++;
	}
	rra(s);
	// print_queue_ab(s);
	sort_three(s, BTOP);
}

void	sort_four_btop(t_stack *s, unsigned int val[])
{
	unsigned int	i;

	i = 0;
	if (val[0] == 3)
	{
		pa(s);
		return (sort_three_btop(s, val[1]));
	}
	while (i < 4 && i >= 0)
	{
		if (val[0] == i)
			pa(s);
		else
			rb(s);
		i++;
	}
	rrb(s);
	rrb(s);
	rrb(s);
	// print_queue_ab(s);
	return (sort_three_btop(s, val[1]));
}

void	sort_four_abot(t_stack *s, unsigned int val[])
{
	unsigned int	i;

	i = 0;
	if (val[0] == 3)
	{
		rra(s);
		rra(s);
		rra(s);
		rra(s);
		// print_queue_ab(s);
		return (sort_three_atop(s, val[3]));
	}
	while (i < 4 && i >= 0)
	{
		rra(s);
		if (val[0] != i)
			pb(s);
		i++;
	}
	// print_queue_ab(s);
	sort_three_btop(s, val[3]);
}

void	sort_four_bbot(t_stack *s, unsigned int val[])
{
	unsigned int	i;

	i = 0;
	if (val[0] == 3)
	{
		rrb(s);
		pa(s);
		rrb(s);
		rrb(s);
		rrb(s);
		// print_queue_ab(s);
		return (sort_three_btop(s, val[3]));
	}
	while (i < 4 && i >= 0)
	{
		rrb(s);
		if (val[0] == i)
			pa(s);
		i++;
	}
	// print_queue_ab(s);
	sort_three_btop(s, val[3]);
}
