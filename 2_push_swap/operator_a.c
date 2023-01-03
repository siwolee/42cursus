/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:38 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/03 15:29:05 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *s)
{
	unsigned int	temp;

	if (!s->atop || !s->atop->next)
		return (0);
	temp = s->atop->val;
	s->atop->val = s->atop->next->val;
	s->atop->next->val = temp;
	return (1);
}

int	pa(t_stack *s)
{
	t_node	*temp;

	if (!s->btop)
		return (0);
	temp = s->btop->next;
	if (s->atop)
		s->atop->before = s->btop;
	s->btop->next->before = 0;
	s->btop->next = s->atop;
	s->btop->next = 0;
	s->atop = s->btop;
	s->btop = temp;
	printf("pa\n");
	return (1);
}

int	ra(t_stack *s)
{
	// t_node	*temp;

	if (!s->atop || !s->abot)
		return (0);
	s->abot->next = s->atop;
	s->atop->before = s->abot;
	s->abot = s->atop;
	s->atop = s->atop->next;
	s->atop->before = 0;
	s->abot->next = 0;
	printf("ra\n");
	return (1);
}

int	rra(t_stack *s)
{
	t_node	*temp;

	if (!s->atop || !s->abot)
		return (0);
	s->abot->before->next = 0;
	s->abot->before = 0;
	s->abot->next = s->atop;
	s->atop->before = s->abot;
	temp = s->abot->before;
	s->atop = s->abot;
	s->abot = temp;
	printf("rra\n");
	return (1);
}