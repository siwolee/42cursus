/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:44:38 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/01 17:20:54 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	sb(t_stack *b)
{
	unsigned int	temp;

	if (!b->top || !b->top->next)
		return (0);
	temp = b->top->val;
	b->top->val = b->top->next->val;
	b->top->next->val = temp;
	printf("sb\n");
	return (1);
}

int	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (!a->top)
		return (0);
	temp = a->top->next;
	if (b->top)
		b->top->before = a->top;
	a->top->next->before = 0;
	a->top->next = b->top;
	a->top->next = 0;
	b->top = a->top;
	a->top = temp;
	printf("pb\n");
	return (1);
}

int	rb(t_stack *b)
{
	// t_node	*temp;

	if (!b->top || !b->bot)
		return (0);
	b->bot->next = b->top;
	b->top->before = b->bot;
	b->bot = b->top;
	b->top = b->top->next;
	b->top->before = 0;
	b->top->next = 0;
	printf("rb\n");
	return (1);
}

int	rrb(t_stack *b)
{
	t_node	*temp;

	if (!b->top || !b->bot)
		return (0);
	b->bot->before->next = 0;
	b->bot->before = 0;
	b->bot->next = b->top;
	b->top->before = b->bot;
	temp = b->bot->before;
	b->top = b->bot;
	b->bot = temp;
	printf("rrb\n");
	return (1);
}