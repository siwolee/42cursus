/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretreat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:36:45 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/22 20:30:09 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

chk_args(int ac, char **av, t_stack a)
{
	t_stack	*a;
	t_node	*node;
	t_node	*next;
	int		i;

	i = 1;
	a = malloc(sizeof(s_stack));
	if (!a)
		return (0);
	a->top = node;
	while (i < ac)
	{
		node = malloc(sizeof(t_node));
		if (!node)
			return (0);
		node->val = ft_atoi(av[i]);
		if (!node)
			delete_stack(a);
		if
	}
	
}

void	init_stack(int *temp, int ac, t_stack *a)
{
	int i;
	t_node	*start;
	t_node	*node;

	i = 0;
	a->top = node;
	node = newnode(temp[0], NULL));
	if (!node)
		return ;//exit
	while (++i < ac)
	{
		if (newnode(temp[i], node == NULL))
			return ;//exit
		node = node->down;
	}
}

t_node	*new_node(int val, t_node *prev)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	if (prev)
		prev->down = new;
	new->val = val;
	new->down = NULL;
	new->up = prev;
	return (new);
}