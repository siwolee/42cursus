/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:38 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/01 17:47:40 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	sb(t_stack *s)
{
	unsigned int	temp;

	if (!s->btop || !s->btop->next)
		return (0);
	temp = s->btop->val;
	s->btop->val = s->btop->next->val;
	s->btop->next->val = temp;
	printf("sb\n");
	return (1);
}

int	pb(t_stack *s)
{
	t_node	*temp;

	if (!s->atop)
		return (0);
	temp = s->atop->next;
	if (s->btop)
		s->btop->before = s->atop;
	s->atop->next = s->btop;
	s->btop = s->atop;
	s->atop = temp;
	s->atop->before = 0;
	printf("pb\n");
	return (1);
}

int	rb(t_stack *s)
{
	// t_node	*temp;

	if (!s->btop || !s->bbot)
		return (0);
	s->bbot->next = s->btop;
	s->btop->before = s->bbot;
	s->bbot = s->btop;
	s->btop = s->btop->next;
	s->btop->before = 0;
	s->btop->next = 0;
	printf("rb\n");
	return (1);
}

int	rrb(t_stack *s)
{
	t_node	*temp;

	if (!s->btop || !s->bbot)
		return (0);
	s->bbot->before->next = 0;
	s->bbot->before = 0;
	s->bbot->next = s->btop;
	s->btop->before = s->bbot;
	temp = s->bbot->before;
	s->btop = s->bbot;
	s->bbot = temp;
	printf("rrb\n");
	return (1);
}