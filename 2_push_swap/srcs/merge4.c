/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:57 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/16 14:10:15 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	get_mostbig_ab(char ab)
{
	if (ab == ATOP)
		return (ABOT);
	else
		return (ATOP);
}

char	get_small_ab(char ab)
{
	if (ab == ATOP || ab == ABOT)
		return (BBOT);
	else
		return (ABOT);
}

void	sort_merge_mostbig(t_stack *s, char ab, int *cnt)
{
	*cnt = *cnt + 1;
	if (ab == ATOP)
		ra(s);
	else if(ab == ABOT)
	{
		rra(s);
	}
	else if (ab == BTOP)
		pa(s);
	else
	{
		rrb(s);
		pa(s);
	}
}

void	sort_merge_big(t_stack *s, char ab, int *cnt)
{
	*cnt = *cnt + 1;
	if (ab == ATOP)
	{
		pb(s);
		if (s->btop->next && (s->btop->val < s->btop->next->val))
			sb(s);
	}
	else if(ab == ABOT)
	{
		rra(s);
		pb(s);
	}
	else if (ab == BTOP)
		rb(s);
	else
		rrb(s);
}

void	sort_merge_small(t_stack *s, char ab, int *cnt)
{
	*cnt = *cnt + 1;
	if (ab == ATOP)
	{
		pb(s);
		rb(s);
	}
	else if(ab == ABOT)
	{
		rra(s);
		pb(s);
		if (s->btop->next && (s->btop->val > s->btop->next->val))
			rb(s);
	}
	else if (ab == BTOP)
	{
		pa(s);
		if (s->atop->next && (s->atop->val > s->atop->next->val))
			ra(s);
	}
	else
	{
		rrb(s);
		pa(s);
		ra(s);
	}	
}

t_node	*get_top(t_stack *s, char ab, int len)
{
	if (ab == ATOP || (ab == ABOT && len == s->asize))
		return (s->atop);
	else if (ab == BTOP || (ab == BBOT && len == s->bsize))
		return (s->btop);
	else if (ab == ABOT)
		return (s->abot);
	else
		return (s->bbot);
}

void sort_merge4(t_stack *s, unsigned int start, unsigned int end, char ab)
{
	int	i;
	int cnt[3] = {0, };
	unsigned int pivot[2];
	t_node	*now;
	int len;
	
	len = end - start + 1;
	pivot[0] = (unsigned int) len / 3;
	pivot[1] = pivot[0] * 2;

	printf("pivot : %d , %d && size = %d\n", pivot[0], pivot[1], len);
	print_queue_ab(s);
	if (len <= 4)
		return (sort_short(s, len, ab));
	i = 0;
	while (i < len)
	{
		now = get_top(s, ab, len);
		if (len > 6 && now->val <= pivot[0])
			sort_merge_small(s, ab, cnt + 0);
		else if (now->val <= pivot[1])
			sort_merge_big(s, ab, cnt + 1);
		else 
			sort_merge_mostbig(s, ab, cnt + 2);
		i++;
	}
	sort_merge4(s, pivot[1] + 1, end, get_mostbig_ab(ab));
	if (len > 6)
	{
		sort_merge4(s, pivot[0] + 1, pivot[1], BTOP);
		sort_merge4(s, start, pivot[0], get_small_ab(ab));
	}
	else
		sort_merge4(s, start, pivot[1], BTOP);
}

