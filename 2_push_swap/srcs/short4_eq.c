/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short4_eq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:04:55 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/16 13:49:35 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max_idx(t_stack *s, unsigned int val[4], char ab)
{
	t_node *a;
	unsigned int i;
	unsigned int max[2];
	unsigned int temp;

	i = -1;
	a = get_top(s, ab, -1);
	val[0] = 0;
	max[0] = 0;
	while (++i < 4)
	{
		val[i] = a->val;
		if (max[0] < a->val)
		{
			max[0] = a->val;
			max[1] = i;
		}
		if (ab <= BTOP)
			a = a->next;
		else
			a = a->prev;
	}
	i = 0;
	temp = max[1];
	max[1] = val[0];
	while (++i < 4)
	{
		if (i <= temp)
		{
			max[0] = val[i];
			val[i] = max[1];
			max[1] = max[0];
		}
		i++;
	}
	val[0] = temp;
	// printf("%d %d %d %d \n", val[0], val[1], val[2], val[3]);
}

void	sort_four_eqaulsize_a(t_stack *s, unsigned int val[])
{
	if (val[0] == 1)
		sa(s);
	if (val[0] <= 1)
		ra(s);
	if (val[0] == 2)
		rra(s);
	// print_queue_ab(s);
	sort_three(s, ATOP);
}

void	sort_four_eqaulsize_b(t_stack *s, unsigned int val[])
{
	if (val[0] == 1)
		sb(s);
	if (val[0] == 2)
		rrb(s);
	if (val[0] >= 2)
		rrb(s);
	pa(s);
	// print_queue_ab(s);
	sort_three(s, BTOP);
}