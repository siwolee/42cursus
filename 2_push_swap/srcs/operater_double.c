/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:38 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 21:16:52 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_stack *s)
{
	unsigned int	temp;

	if (!s->atop || !s->atop->next)
		return (sb(s));
	if (!s->btop || !s->btop->next)
		return (sa(s));
	temp = s->atop->val;
	s->atop->val = s->atop->next->val;
	s->atop->next->val = temp;
	temp = s->btop->val;
	s->btop->val = s->btop->next->val;
	s->btop->next->val = temp;
	add_act_len(s->act, SS);
}

void	rrr(t_stack *s)
{
	t_node	*temp;

	if (s->bsize < 2 || !s->btop || !s->bbot)
		return (rra(s));
	if (s->asize < 2 || !s->atop || !s->abot)
		return (rrb(s));
	temp = s->abot->prev;
	s->abot->prev->next = 0;
	s->abot->prev = 0;
	s->abot->next = s->atop;
	s->atop->prev = s->abot;
	s->atop = s->abot;
	s->abot = temp;
	temp = s->bbot->prev;
	s->bbot->prev->next = 0;
	s->bbot->prev = 0;
	s->bbot->next = s->btop;
	s->btop->prev = s->bbot;
	s->btop = s->bbot;
	s->bbot = temp;
	add_act_len(s->act, RRR);
	return ;
}

void	rr(t_stack *s)
{
	if (!s->btop || s->bsize < 2)
		return (ra(s));
	if (s->asize < 2 || !s->atop)
		return (rb(s));
	if (s->bbot)
		s->bbot->next = s->btop;
	s->btop->prev = s->bbot;
	s->bbot = s->btop;
	s->btop = s->btop->next;
	s->btop->prev = 0;
	s->bbot->next = 0;
	s->atop->prev = s->abot;
	s->abot = s->atop;
	s->atop = s->atop->next;
	s->atop->prev = 0;
	s->abot->next = 0;
	add_act_len(s->act, RR);
}
