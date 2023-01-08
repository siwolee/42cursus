/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretreat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:36:45 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/08 23:01:09 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chker.h"

void	atoi_arr(int len, char **av, int *res)
{
	int	i;
	int	e;
	int	val;

	i = 0;
	while (i < len)
	{
		val = ft_atoi(av[i]);
		if (val == 0 && av[i][0] != 0)
		{
			exit(1);
		}
		res[i] = val;
		e = 0;
		while (e < i)
		{
			if (res[e] == val)
				{
					exit(1);
				}
			e++;
		}
		i++;
	}
	return ;
}

t_node	*newnode(int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->val = val;
	new->next = 0;
	new->prev = 0;
	return (new);
}

void	init_stack(t_stack *s, int res[], int len)
{
	int i;
	t_node	*node;
	t_node	*next;

	if (res == NULL)
	{
		s->atop = NULL;
		s->abot = NULL;
		s->asize = 0;
		return ;
	}
	s->btop = s->bbot = 0;
	s->bsize = 0;
	node = newnode(res[0]);
	s->atop = node;
	i = 1;
	while (i < len)
	{
		next = newnode(res[i]);
		node->next = next;
		next->prev = node;
		node = node->next;
		i++;
	}
	s->asize = len;
	s->abot = next;
}
