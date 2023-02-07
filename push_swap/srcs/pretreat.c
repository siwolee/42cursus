/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pretreat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:36:45 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/30 19:00:17 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pretreat(t_stack *s, char **av, int len)
{
	int			i;
	int			val;
	t_pre_val	*pre;

	i = 0;
	s->asize = len;
	if (chk_split(av))
	{
		av = ft_split(*av, ' ', s);
	}
	pre = malloc(sizeof(t_pre_val) * s->asize);
	if (!pre)
		call_err(NULL, "Error");
	while (av[i])
	{
		val = ft_atoi(av[i]);
		pre[i].val = val;
		pre[i].idx = 1;
		indexing(pre, i, val);
		i++;
	}
	init_stack(s, pre, i);
	free(pre);
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
			call_err(NULL, "Error");
		}
		e++;
	}
	return (0);
}

long long	chk_int(long long re, char c, int sign)
{
	long long	res;

	if (c < '0' || c > '9')
		return (0);
	res = re * 10 + (c - '0') * sign;
	if (res > 2147483647 || res < -2147483648)
		call_err(NULL, "Error");
	else
		return (res);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	re;
	size_t		i;

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
		re = chk_int(re, str[i], sign);
		i++;
	}
	return ((int)re);
}

int	chk_split(char **av)
{
	int	i;
	int	e;
	int	flag;

	flag = 0;
	e = 0;
	while (av[e] != 0)
	{
		i = -1;
		while (av[e][++i] != 0)
		{
			if (av[e][i] == ' ')
			{
				flag++;
				continue ;
			}
			else if (av[e][i] >= '0' && av[e][i] <= '9')
				continue ;
			else if (av[e][i] == '-' || av[e][i] == '+')
				continue ;
			call_err(NULL, "Error");
		}
		e++;
	}
	return (flag);
}
