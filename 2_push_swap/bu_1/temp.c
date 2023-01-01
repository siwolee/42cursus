/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:22:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/01 15:05:11 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		i;

	printf("\na : ");
	node = a->top;
	i = 0;
	while (node)
	{
		printf("%d ", node->val);
		node = node->next;
		i++;
	}
	printf(" : count - %d\n", i);
	printf("b : ");
	node = b->top;
	i = 0;
	while (node)
	{
		printf("%d ", node->val);
		node = node->next;
		i++;
	}
	printf(" : count - %d\n", i);
}

void	print_stack(t_stack *a)
{
	t_node	*node;
	int		i;

	printf("\na : ");
	node = a->top;
	i = 0;
	while (node)
	{
		printf("%d ", node->val);
		node = node->next;
		i++;
	}
	printf(" : count - %d\n", i);
}