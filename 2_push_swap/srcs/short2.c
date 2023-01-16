/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:04:55 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/16 20:07:35 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *s, char ab)
{
	if (ab == ATOP)
		return (sort_two_atop(s, s->atop->val, s->atop->next->val));
	else if (ab == BTOP)
		return (sort_two_btop(s, s->btop->val, s->btop->next->val));
	else if (ab == ABOT)
		return (sort_two_abot(s, s->abot->val, s->abot->prev->val));
	else
		return (sort_two_bbot(s, s->bbot->val, s->bbot->prev->val));
}

void	sort_two_atop(t_stack *s, unsigned int a, unsigned int b)
{
	if (a > b)
		sa(s);
}

void	sort_two_btop(t_stack *s, unsigned int a, unsigned int b)
{
	pa(s);
	pa(s);
	if (b > a)
		sa(s);
}

void	sort_two_abot(t_stack *s, unsigned int a, unsigned int b)
{
	if (s->asize == 2)
		return (sort_two_atop(s, b, a));
	rra(s);
	rra(s);
	if (b > a)
		sa(s);
}

void	sort_two_bbot(t_stack *s, unsigned int a, unsigned int b)
{
	if (s->bsize == 2)
		return (sort_two_btop(s, b, a));
	rrb(s);
	rrb(s);
	if (a > b)
		sb(s);
	pa(s);
	pa(s);
}