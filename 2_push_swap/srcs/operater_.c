/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:38 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/03 16:40:47 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	s_(t_stack *s, int ab)
{
	unsigned int	temp;

	if (ab == 0)
	{
		if (!s->atop || !s->atop->next)
			return ;
		temp = s->atop->val;
		s->atop->val = s->atop->next->val;
		s->atop->next->val = temp;
		printf("sa\n");
		return ;
	}
	if (!s->btop || !s->btop->next)
		return ;
	temp = s->btop->val;
	s->btop->val = s->btop->next->val;
	s->btop->next->val = temp;
	printf("sb\n");
}

void	p_(t_stack *s, int ab)
{
	t_node	*temp;

	if (ab == 0)
	{
		if (!s->btop)
			return ;
		temp = s->btop->next;
		if (s->atop)
			s->atop->before = s->btop;
		s->btop->next = s->atop;
		s->atop = s->btop;
		s->btop = temp;
		s->btop->before = 0;
		printf("pa\n");
		s->asize++;
		s->bsize--;
		return ;
	}
	if (!s->atop)
		return ;
	temp = s->atop->next;
	if (s->btop)
		s->btop->before = s->atop;
	s->atop->next = s->btop;
	s->btop = s->atop;
	s->atop = temp;
	s->atop->before = 0;
	s->asize--;
	s->bsize++;
	printf("pb\n");
}

void	r_(t_stack *s, int ab)
{
	if (ab == 0)
	{
		if (s->asize < 2)
			return ;
		s->abot->next = s->atop;
		s->atop->before = s->abot;
		s->abot = s->atop;
		s->atop = s->atop->next;
		s->atop->before = 0;
		s->abot->next = 0;
		printf("ra\n");
		return ;
	}
	if (s->bsize < 2)
		return ;
	if (s->bbot)
	s->bbot->next = s->btop;
	s->btop->before = s->bbot;
	s->bbot = s->btop;
	s->btop = s->btop->next;
	s->btop->before = 0;
	s->bbot->next = 0;
	printf("rb\n");
}

void	rb(t_stack *s)
{
	if (!s->btop)
		return ;
	if (s->bsize < 2)
		return ;
	if (s->bbot)
		s->bbot->next = s->btop;
	s->btop->before = s->bbot;
	s->bbot = s->btop;
	s->btop = s->btop->next;
	s->btop->before = 0;
	s->bbot->next = 0;
	printf("rb\n");
}

void	rr_(t_stack *s, int ab)
{
	t_node	*temp;

	if (ab == 1)
	{
		if (!s->atop || !s->abot)
			return ;
		s->abot->before->next = 0;
		s->abot->before = 0;
		s->abot->next = s->atop;
		s->atop->before = s->abot;
		temp = s->abot->before;
		s->atop = s->abot;
		s->abot = temp;
		printf("rra\n");
		return ;
	}
	if (!s->btop || !s->bbot)
		return ;
	s->bbot->before->next = 0;
	s->bbot->before = 0;
	s->bbot->next = s->btop;
	s->btop->before = s->bbot;
	temp = s->bbot->before;
	s->btop = s->bbot;
	s->bbot = temp;
	printf("rrb\n");
}