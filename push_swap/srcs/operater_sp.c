/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:38 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/19 19:20:02 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *s)
{
	unsigned int	temp;

	if (!s->atop || !s->atop->next)
		return ;
	temp = s->atop->val;
	s->atop->val = s->atop->next->val;
	s->atop->next->val = temp;
	add_act_len(s->act, SA);
}

void	sb(t_stack *s)
{
	unsigned int	temp;

	if (!s->btop || !s->btop->next)
		return ;
	temp = s->btop->val;
	s->btop->val = s->btop->next->val;
	s->btop->next->val = temp;
	add_act_len(s->act, SB);
}

void	pa(t_stack *s)
{
	t_node	*temp;

	if (!s->btop)
		return ;
	temp = s->btop->next;
	if (s->atop)
		s->atop->prev = s->btop;
	s->btop->next = s->atop;
	s->atop = s->btop;
	s->btop = temp;
	if (s->btop)
		s->btop->prev = 0;
	s->asize++;
	s->bsize--;
	if (s->bsize == 1)
		s->bbot = s->btop;
	if (s->asize == 1)
		s->abot = s->atop;
	if (s->asize == 0)
		s->abot = 0;
	add_act_len(s->act, PA);
	return ;
}

void	pb(t_stack *s)
{
	t_node	*temp;

	if (!s->atop)
		return ;
	temp = s->atop->next;
	if (s->btop)
		s->btop->prev = s->atop;
	s->atop->next = s->btop;
	s->btop = s->atop;
	s->atop = temp;
	if (s->atop)
		s->atop->prev = 0;
	s->asize--;
	s->bsize++;
	if (s->bsize == 1)
		s->bbot = s->btop;
	if (s->asize == 1)
		s->abot = s->atop;
	if (s->bsize == 0)
		s->bbot = 0;
	add_act_len(s->act, PB);
}
