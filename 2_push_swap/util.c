/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:14:10 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/18 23:17:20 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include.h"

int	s(t_stack *a)
{
	int	temp;

	if (!a->top || !a->top->down)
		return (0);
	temp = a->top->val;
	a->top->val = a->top->down->val;
	a->top->down->val = temp;
	printf("s%s\n", NAME_(a));
	return (1);
}

int	p(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b->top)
		return (0);
	node = b->top;
	b->top = b->top->down;
	if (b->top)
		b->top->up = 0;
	node->down = a->top;
	if (a->top)
	{
		a->top->up = node;
		node->down = a->top;
	}
	a->top = node;
	node->up = 0;
	if (!a->bot)
		a->bot = node;
	printf("p%s\n", NAME_(a));
	return (1);
}

int r(t_stack *a)
{
	t_node	*node;
	
	if (!a->top)
		return (0);
	node = a->top;
	a->top = a->top->down;
	a->top->up = 0;
	node->up = a->bot;
	a->bot->down = node;
	node->down = 0;
	a->bot = node;
	printf("r%s\n", NAME_(a));
	return (1);
}

int rr(t_stack *a)
{
	t_node	*node;
	
	if (!a->bot)
		return (0);
	node = a->bot;
	a->bot = a->bot->up;
	a->bot->down = 0;
	node->down = a->top;
	a->top->up = node;
	node->up = 0;
	a->top = node;
	printf("rr%s\n", NAME_(a));
	return (1);
}