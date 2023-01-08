/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretreat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:36:45 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/07 18:27:12 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pre_val	*atoi_arr(int len, char **av, int *res)
{
	int	i;
	int	e;
	int	val;
	t_pre_val	*pre;

	i = 0;
	pre = malloc(sizeof(t_pre_val) * len);
	if (!pre)
		exit(1);
	while (i < len)
	{
		val = ft_atoi(av[i]);
		if (val == 0 && av[i][0] != 0)
		{
			free(pre);
			exit(1);
		}
		pre[i].val = val;
		pre[i].idx = i;
		res[i] = val;
		e = 0;
		while (e < i)
		{
			if (pre[e].val == val)
				{
					printf("중복입니다..\n");
					free(pre);
					exit(1);
				}
			e++;
		}
		i++;
	}
	return (pre);
}

static void	swap_pre(t_pre_val *a, t_pre_val *b)
{
	int	tval;
	int tidx;

	tval = a->val;
	a->val = b->val;
	b->val = tval;
	tidx = a->idx;
	a->idx = b->idx;
	b->idx = tidx;
}

void	pre_quick_sort(t_pre_val *data, int start, int end)
{
	// int	*res;
	int	i;
	int	j;
	int	pivot;

	// res = ft_calloc(end, sizeof(int));
	pivot = start;
	i = start + 1;
	j = end - 1;
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
			swap_pre(data + j, data + pivot);
		}
		else
		{
			swap_pre(data + i, data + j);
		}
	}
	pre_quick_sort(data, start, j - 1);
    pre_quick_sort(data, j + 1, end);
}

void	indexing(t_pre_val pre[], int res[], int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		res[i] = 0;
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (res[pre[i].idx] != 0)
			exit(0);
		res[pre[i].idx] = i + 1;
		i++;
	}
	free(pre);
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

void	init_index(t_pre_val *pre, int *res, int len)
{
	int arr[2147483647] = {0,};
	int 	i;

	while (pre)
	{
		arr[pre->val] = pre->idx;
		pre++;
	}
	 i = 0;
	while (i < 2147483647 && arr[i] < len)
	{
		if (arr[i] != 0)
		{
			res[arr[i]] = i + 1;
		}
		i++;
	}
}