/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:38 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 21:16:58 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *s)
{
	if (s->asize < 2 || !s->atop)
		return ;
	if (s->abot)
		s->abot->next = s->atop;
	s->atop->prev = s->abot;
	s->abot = s->atop;
	s->atop = s->atop->next;
	s->atop->prev = 0;
	s->abot->next = 0;
	add_act_len(s->act, RA);
	return ;
}

void	rb(t_stack *s)
{
	if (!s->btop)
		return ;
	if (s->bsize < 2)
		return ;
	if (s->bbot)
		s->bbot->next = s->btop;
	s->btop->prev = s->bbot;
	s->bbot = s->btop;
	s->btop = s->btop->next;
	s->btop->prev = 0;
	s->bbot->next = 0;
	add_act_len(s->act, RB);
}

void	rra(t_stack *s)
{
	t_node	*temp;

	if (s->asize < 2 || !s->atop || !s->abot)
		return ;
	temp = s->abot->prev;
	s->abot->prev->next = 0;
	s->abot->prev = 0;
	s->abot->next = s->atop;
	s->atop->prev = s->abot;
	s->atop = s->abot;
	s->abot = temp;
	add_act_len(s->act, RRA);
	return ;
}

void	rrb(t_stack *s)
{
	t_node	*temp;

	if (s->bsize < 2 || !s->btop || !s->bbot)
		return ;
	temp = s->bbot->prev;
	s->bbot->prev->next = 0;
	s->bbot->prev = 0;
	s->bbot->next = s->btop;
	s->btop->prev = s->bbot;
	s->btop = s->bbot;
	s->bbot = temp;
	add_act_len(s->act, RRB);
}
