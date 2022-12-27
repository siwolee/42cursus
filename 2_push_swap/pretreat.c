/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretreat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:36:45 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/27 21:21:02 by siwolee          ###   ########.fr       */
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
	int		i;
	t_node	*start;
	t_node	*node;

	i = 0;
	a->top = node;
	node = newnode(temp[0], NULL));
	if (!node)
		return ; //exit
	while (++i < ac)
	{
		if (newnode(temp[i], node == NULL))
			return ; //exit
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

t_stack	*init(int ac, char **av)
{
	int	*pre;
	int	i;

	pre = ft_calloc(ac - 1, sizeof(int));
	if (!pre)
		return (0);
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '0' && av[i][1] == 0)
		{
			pre[i] == 0;
			continue ;
		}
		pre[i] = ft_atoi(av[i]);
	}
	pre = pre_sort(pre, ac - 1);
	return (set_stack(pre, ac - 1));
}

int	*pre_sort(int *draft, int len)
{
	unsigned int	idx;
	int				arr1[4294967295];
	unsigned int	*arr2;
	int				i;

	i = 0;
	arr2 = ft_calloc(len, sizeof(int));
	if (!arr2)
		return (0);
	while (i < len)
	{
		arr1[draft[i]] = i;
		i++;
	}
	i = 0;
	while (i < len)
	{
		arr2[i] = arr1[draft[i]];
		i++;
	}
	free(draft);
	return (arr2);
}

int	pre_quick_sort(int *data, int start, int end)
{
	int	*res;
	int	i;
	int	j;
	int	pivot;
	int	temp;

	res = ft_calloc(end, sizeof(int));
	pivot = 0;
	i = 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && data[i] <= data[pivot])
		{
			i++;
		}
		while (j > start && data[j] >= data[pivot])
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
	pre_quick_sort(data, start, j - 1);
    pre_quick_sort(data, j + 1, end);
}
