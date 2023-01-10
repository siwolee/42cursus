/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:14:10 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/10 15:45:24 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

// void	indexing(t_pre_val pre[], int res[], int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		res[i] = 0;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (res[pre[i].idx] != 0)
// 			exit(0);
// 		res[pre[i].idx] = i + 1;
// 		i++;
// 	}
// 	free(pre);
// }

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