/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:33:33 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/24 20:52:25 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	chk_sorted_final(t_stack *s)
{
	int				i;
	t_node			*n;

	if (s->btop || !s->atop)
		return (1);
	i = 1;
	n = s->atop;
	while (n->next)
	{
		if (n->val >= n->next->val)
		{
			return (1);
		}
		i++;
		n = n->next;
	}
	return (0);
}

int	chk_sorted(t_stack *s, int len)
{
	int				i;
	t_node			*n;

	if (!s->atop)
		return (1);
	i = 1;
	n = s->atop;
	while (n->next)
	{
		if (n->val >= n->next->val)
		{
			return (1);
		}
		i++;
		n = n->next;
	}
	if (i == len)
		return (0);
	else
		return (1);
}
