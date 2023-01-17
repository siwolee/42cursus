/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:17:10 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 21:02:15 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdarg.h>

void	ft_bzero(void *s, size_t n)
{
	while (n)
	{
		*(char *)s = 0;
		n--;
		s++;
	}
}

t_act	*init_act(void)
{
	t_act	*next;

	next = malloc(sizeof(t_act));
	if (!next)
		call_err("malloc");
	ft_bzero(next->arr, ACTMAX);
	next->next = NULL;
	return (next);
}

t_act	*add_act(t_act *act)
{
	t_act	*next;

	next = malloc(sizeof(t_act));
	if (!next)
		call_err("malloc");
	ft_bzero(next->arr, ACTMAX);
	next->next = NULL;
	act->next = next;
	return (next);
}

void	add_act_len(t_act *act, char newact)
{
	static int	len;
	int			i;

	i = 0;
	while (act->next)
		act = act->next;
	if (len == ACTMAX)
	{
		act = add_act(act);
		len = 0;
	}
	act->arr[len] = newact;
	len++;
	if (len < ACTMAX)
		act->arr[len] = 0;
}
