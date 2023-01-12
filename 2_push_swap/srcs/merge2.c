/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:00:28 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/11 13:58:51 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*get_top(t_stack *s, char ab)
{
	if (ab == ATOP)
		return (s->atop);
	else if (ab == BTOP)
		return (s->btop);
	else if (ab == ABOT)
		return (s->abot);
	else
		return (s->bbot);
}

char	get_big_ab(char ab)
{
	if (ab == ATOP)
		return (BTOP);
	else if (ab == BTOP)
		return (ATOP);
	else if (ab == ABOT)
		return (BTOP);
	else
		return (ATOP);
}

char	get_small_ab(char ab)
{
	if (ab == ATOP)
		return (BBOT);
	else if (ab == BTOP)
		return (ABOT);
	else if (ab == ABOT)
		return (BBOT);
	else
		return (ABOT);
}

void	merge_sort(t_stack *s, char ab, int len, unsigned int pivot)
{
	t_node		*node;
	int		cnt[3];

	if (len <= 3)
		return (sort_short(s, len, ab));
	node = get_top(s, ab);
	ft_bzero(cnt, sizeof(int) * 3);
	while (node && cnt[4] < len)
	{
		if (node->val > pivot)
			sort_big(s, ab) && cnt[0]++;
		else
			sort_small(s, ab) && cnt[1]++;
		if (ab <= BTOP)
			node = node->next;
		else
			node = node->prev;
		cnt[3]++;
	}
	mergesort(s, get_big_ab(ab), cnt[0], pivot + pivot >> 2);
	mergesort(s, get_small_ab(ab), cnt[1], pivot >> 2);
}

int	sort_big(t_stack *s, char ab)
{
	if (ab == ATOP)
		execute(s, "4");
	else if (ab == BTOP)
		execute(s, "3");
	else if (ab == ABOT)
		execute(s, "74");
	else
		execute(s, "83");
}

int	sort_small(t_stack *s, char ab)
{
	if (ab == ATOP)
		execute(s, "46");
	else if (ab == BTOP)
		execute(s, "35");
	else if (ab == ABOT)
		execute(s, "746");
	else
		execute(s, "835");
}
