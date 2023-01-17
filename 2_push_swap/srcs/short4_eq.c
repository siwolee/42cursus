/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short4_eq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:04:55 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 21:13:13 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_max_idx(t_stack *s, char ab)
{
	t_node			*a;
	unsigned int	i;
	unsigned int	val[4];
	unsigned int	max_idx;

	i = -1;
	a = get_top(s, &ab, 4);
	max_idx = 0;
	while (++i < 4)
	{
		val[i] = a->val;
		if (val[max_idx] < a->val)
		{
			max_idx = i;
		}
		if (ab <= BTOP)
			a = a->next;
		else
			a = a->prev;
	}
	return (max_idx);
}

void	sort_four_eqaulsize_a(t_stack *s, unsigned int max_idx)
{
	if (max_idx == 1)
		sa(s);
	if (max_idx <= 1)
		ra(s);
	if (max_idx == 2)
		rra(s);
	sort_three(s, ATOP);
}

void	sort_four_eqaulsize_b(t_stack *s, unsigned int max_idx)
{
	if (max_idx == 1)
		sb(s);
	if (max_idx == 2)
		rrb(s);
	if (max_idx >= 2)
		rrb(s);
	pa(s);
	sort_three(s, BTOP);
}
