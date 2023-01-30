/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:32:05 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/23 16:12:49 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_one(t_stack *s, char ab)
{
	if (ab == ATOP)
		return ;
	else if (ab == BTOP)
		pa(s);
	else if (ab == ABOT)
		rra(s);
	else
	{
		rrb(s);
		pa(s);
	}
}

void	sort_short(t_stack *s, t_pivot *p, char ab)
{
	if (ab == ATOP && !chk_sorted(s, p->len))
		return (free(p));
	if (p->len == 2)
		sort_two(s, ab);
	else if (p->len == 3)
		sort_three(s, ab);
	else if (p->len == 4)
		(sort_four(s, ab));
	else if (p->len == 1)
		sort_one(s, ab);
	free(p);
}
