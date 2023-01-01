/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretreat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:36:45 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/01 22:13:52 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// chk_args(int ac, char **av, t_stack a)
// {
// 	t_stack	*a;
// 	t_node	*node;
// 	t_node	*next;
// 	int		i;

// 	i = 1;
// 	a = malloc(sizeof(s_stack));
// 	if (!a)
// 		return (0);
// 	s->atop = node;
// 	while (i < ac)
// 	{
// 		node = malloc(sizeof(t_node));
// 		if (!node)
// 			return (0);
// 		node->val = ft_atoi(av[i]);
// 		if (!node)
// 			delete_stack(a);
// 		if
// 	}
// }

void	pre_quick_sort(t_pre_val data[], int start, int end)
{
	// int	*res;
	int	i;
	int	j;
	int	pivot;
	t_pre_val	temp;

	// res = ft_calloc(end, sizeof(int));
	pivot = start;
	i = start + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i <= end && data[i].val <= data[pivot].val)
		{
			i++;
		}
		while (j > start && data[j].val >= data[pivot].val)
		{
			j--;
		}
		if (i > j)
		{
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	pre_quick_sort(data, start, j - 1);
    pre_quick_sort(data, j + 1, end);
}

void	indexing(t_pre_val pre[], int res[], int len)
{
	int	i;

	i = 1;
	while (i != len)
	{
		res[pre[i].idx] = i;
		i++;
	}
}

t_node	*newnode(int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->val = val;
	new->next = 0;
	new->before = 0;
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
	s->btop = s->bbot = NULL;
	s->bsize = 0;
	node = newnode(res[0]);
	s->atop = node;
	i = 1;
	while (res[i] != 0)
	{
		next = newnode(res[i]);
		node->next = next;
		next->before = node;
		node = node->next;
		i++;
	}
	s->asize = len;
	s->abot = next;
}
