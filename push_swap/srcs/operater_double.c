/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:38 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/24 19:20:07 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_stack *s)
{
	if (!s->atop || !s->atop->next)
		return (sb(s));
	if (!s->btop || !s->btop->next)
		return (sa(s));
	sa(s);
	sb(s);
	add_act_len(s->act, SS);
}

void	rrr(t_stack *s)
{
	if (s->bsize < 2 || !s->btop || !s->bbot)
		return (rra(s));
	if (s->asize < 2 || !s->atop || !s->abot)
		return (rrb(s));
	rra(s);
	rrb(s);
	return ;
}

void	rr(t_stack *s)
{
	if (!s->btop || s->bsize < 2)
		return (ra(s));
	if (s->asize < 2 || !s->atop)
		return (rb(s));
	ra(s);
	rb(s);
	add_act_len(s->act, RR);
}
