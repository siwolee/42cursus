/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:38 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/16 22:53:13 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chker.h"

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
}

void	sa(t_stack *s)
{
	unsigned int	temp;

	if (!s->atop || !s->atop->next)
		return ;
	temp = s->atop->val;
	s->atop->val = s->atop->next->val;
	s->atop->next->val = temp;
}

void	sb(t_stack *s)
{
	unsigned int	temp;

	if (!s->btop || !s->btop->next)
		return ;
	temp = s->btop->val;
	s->btop->val = s->btop->next->val;
	s->btop->next->val = temp;
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
}

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
}

void	rrr(t_stack *s)
{
	t_node	*temp;

	if (s->bsize < 2 || !s->btop || !s->bbot)
		return (rra(s));
	if (s->asize < 2|| !s->atop || !s->abot)
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
	return ;
}

void	rra(t_stack *s)
{
	t_node	*temp;

	if (s->asize < 2|| !s->atop || !s->abot)
		return ;
	temp = s->abot->prev;
	s->abot->prev->next = 0;
	s->abot->prev = 0;
	s->abot->next = s->atop;
	s->atop->prev = s->abot;
	s->atop = s->abot;
	s->abot = temp;
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
}