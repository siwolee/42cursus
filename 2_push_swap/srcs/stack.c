/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:42 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/19 19:40:32 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*newnode(int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		call_err("");
	new->val = val;
	new->next = 0;
	new->prev = 0;
	return (new);
}

int	init_stack(t_stack *s, t_pre_val *pre, int len)
{
	int		i;
	t_node	*node;
	t_node	*next;

	s->btop = 0;
	s->bbot = 0;
	s->bsize = 0;
	node = newnode(pre[0].idx);
	s->atop = node;
	i = 1;
	while (i < len)
	{
		next = newnode(pre[i].idx);
		node->next = next;
		next->prev = node;
		node = node->next;
		i++;
	}
	s->asize = len;
	s->abot = next;
	s->act = init_act();
	s->split = NULL;
	return (0);
}

void	free_stack(t_stack *s)
{
	t_node	*next;
	t_act	*next_act;

	next = s->atop;
	while (next)
	{
		next = s->atop->next;
		free(s->atop);
		s->atop = next;
	}
	next = s->btop;
	while (next)
	{
		next = s->btop->next;
		free(s->btop);
		s->btop = next;
	}
	next_act = s->act;
	while (next_act)
	{
		next_act = s->act->next;
		free(s->act);
		s->act = next_act;
	}
	free(s->split);
}
