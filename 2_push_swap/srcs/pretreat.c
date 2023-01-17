/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretreat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:36:45 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 21:02:32 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pretreat(t_stack *s, char **av, int len)
{
	int			i;
	int			val;
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
			return (1);
		}
		pre[i].val = val;
		pre[i].idx = 1;
		if (indexing(pre, i, val))
			return (1);
		i++;
	}
	if (init_stack(s, pre, len))
		return (1);
	free(pre);
	return (0);
}

int	indexing(t_pre_val *pre, int i, int val)
{
	int	e;

	e = 0;
	while (i > e)
	{
		if (pre[e].val > val)
		{
			pre[e].idx++;
		}
		else if (pre[e].val < val)
		{
			if (pre[i].idx <= pre[e].idx)
				pre[i].idx = pre[e].idx + 1;
		}
		else
		{
			return (1);
		}
		e++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		re;
	size_t	i;

	sign = 1;
	re = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		re = re * 10 + str[i] - '0';
		i++;
	}
	re *= sign;
	return (re);
}
