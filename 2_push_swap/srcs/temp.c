/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:22:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/01 22:13:50 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "stdio.h"

void	print_stacks(t_stack *s)
{
	t_node	*node;
	int		i;

	printf("\na : ");
	node = s->atop;
	i = 0;
	while (node)
	{
		printf("%d ", node->val);
		node = node->next;
		i++;
	}
	printf(" : count - %d\n", i);
	printf("b : ");
	node = s->btop;
	i = 0;
	while (node)
	{
		printf("%d ", node->val);
		node = node->next;
		i++;
	}
	printf(" : count - %d\n", i);
}

void	print_stack(t_stack *s, int ab)
{
	t_node	*node;
	int		i;

	i = 0;
	if (ab == 0)
	{
		printf("\na : ");
		node = s->atop;
		while (node)
		{
			printf("%d ", node->val);
			node = node->next;
			i++;
		}
	}
	else if (ab == 1)
	{
		printf("\nb : ");
		node = s->btop;
		while (node)
		{
			printf("%d ", node->val);
			node = node->next;
			i++;
		}
	}
	printf("... count : %d\n", i);
}