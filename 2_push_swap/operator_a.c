/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:38 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/27 18:16:49 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	sa(t_stack *a)
{
	unsigned int	temp;

	if (!a->top || !a->top->next)
		return (0);
	temp = a->top->val;
	a->top->val = a->top->next->val;
	a->top->next->val = temp;
	return (1);
}

int	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!a->top || !b->top)
		return (0);
	temp = b->top->next;
	a->top->before = b->top;
	b->top->next = a->top;
	b->top->next->before = 0;
	b->top->next = 0;
	a->top = b->top;
	b->top = temp;
	return (1);
}

int	ra(t_stack *a)
{
	t_node	*temp;

	if (!a->top || !a->bot)
		return (0);
	a->bot->next = a->top;
	a->top->before = a->bot;
	a->top->next->before = 0;
	a->top->next = 0;
	temp = a->top;
	a->top = a->top->next;
	a->bot = temp;
	return (1);
}

int	rra(t_stack *a)
{
	t_node	*temp;

	if (!a->top || !a->bot)
		return (0);
	a->bot->before->next = 0;
	a->bot->before = 0;
	a->bot->next = a->top;
	a->top->before = a->bot;
	temp = a->bot->before;
	a->top = a->bot;
	a->bot = temp;
	return (1);
}