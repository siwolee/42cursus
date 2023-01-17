/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:57 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 21:14:35 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*get_top(t_stack *s, char *ab, int len)
{
	if (*ab == ATOP || (*ab == ABOT && len == s->asize))
	{
		*ab = ATOP;
		return (s->atop);
	}
	else if (*ab == BTOP || (*ab == BBOT && len == s->bsize))
	{
		*ab = BTOP;
		return (s->btop);
	}
	else if (*ab == ABOT)
		return (s->abot);
	else
		return (s->bbot);
}

t_pivot	*new_pivot(unsigned int start, unsigned int end)
{
	t_pivot	*p;

	p = malloc(sizeof(t_pivot));
	if (!p)
		call_err("pivot malloc\n");
	p->len = end - start + 1;
	p->pivot1 = (unsigned int)(p->len / 3);
	p->pivot2 = p->pivot1 * 2 + start;
	p->pivot1 += start;
	return (p);
}

void	sort_merge(t_stack *s, unsigned int start, unsigned int end, char ab)
{
	t_node			*now;
	t_pivot			*p;
	unsigned int	i;

	p = new_pivot(start, end);
	if (p->len <= 4)
		return (sort_short(s, p, ab));
	i = 0;
	while (i < p->len)
	{
		now = get_top(s, &ab, p->len);
		if (now->val <= p->pivot1)
			sort_merge_small(s, ab);
		else if (now->val <= p->pivot2)
			sort_merge_big(s, ab);
		else
			sort_merge_mostbig(s, ab);
		i++;
	}
	sort_merge(s, p->pivot2 + 1, end, get_mostbig_ab(ab));
	sort_merge(s, p->pivot1 + 1, p->pivot2, get_big_ab(ab));
	sort_merge(s, start, p->pivot1, get_small_ab(ab));
	free(p);
}
