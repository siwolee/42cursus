/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:54:59 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/18 13:41:58 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include.h"

int init_stack(int *temp, t_stack **a)
{
	int	i;
	t_node 	*node;
	*a = malloc(sizeof(t_stack));
	if (!*a)
		return (0);
	if (!temp)
	{
		(*a)->top = NULL;
		(*a)->bot = NULL;
		return (1);
	}
	node = malloc(sizeof(t_node));
	node->val = temp[0];
	node->up = 0;
	(*a)->top = node;
	i = 1;
	while (temp[i] != -1)
	{
		node->down = malloc(sizeof(t_node));
		node->down->up = node;
		node = node->down;
		node->val = temp[i];
		i++;
	}
	node->down = 0;
	(*a)->bot = node;
	return (1);
}

void print_stack(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node != 0)
	{
		printf("%d ", node->val);
		node = node->down;
	}
	printf("\n");
}