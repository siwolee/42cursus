/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:57 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/12 21:55:16 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



void	mergesort_atop(t_stack *s, unsigned int start, unsigned int end)
{
	int mb;
	int len;
	int move;
	int	i;
	t_node	*now, *next;

	len = end - start + 1;
	mb = 4;
	printf("%smergesort ATOP : start %d, end %d, len %d, mb %d\n\033[0m", C_PINK, start, end, len, mb);
	print_queue_ab(s);
	if (len & 1)
		mb = 3;
	if (len <= 4)
	{
		sort_short(s, len, ATOP);
		return ;
	}
	move = (len - mb) >> 1;
	i = 0;
	now = s->atop;
	if (pri_sort(s, len, ATOP))
		return ;
	while (i < len)
	{
		next = now->next;
		if (now->val > end - mb)
		{
			execute(s, "5");
		}
		else if (move >= 4 && now->val < start + move)
			execute(s, "46");
		else
		{
			execute(s, "4");
		}
		now = next;
		i++;
	}
	sort_short(s, mb, ABOT);
	if (move >= 4)
	{
		mergesort_btop(s, start + move, end - mb); //b
		mergesort_btop(s, start, start + move - 1); // s
	}
	else
		mergesort_btop(s, start, end - mb); //b
}

void	mergesort_btop(t_stack *s, unsigned int start, unsigned int end)
{
	int mb;
	int len;
	int move;
	int	i;
	t_node	*now, *next;

	len = end - start + 1;
	mb = 4;	
	printf("%smergesort BTOP : start %d, end %d, len %d, mb %d\n\033[0m", C_PINK, start, end, len, mb);
	print_queue_ab(s);
	if (len & 1)
		mb = 3;
	if (len <= 4)
	{
		sort_short(s, len, BTOP);
		return ;
	}
	move = (len - mb) >> 1;
	i = 0;
	now = s->btop;
	while (i < len)
	{
		next = now->next;
		if (now->val > end - mb)
		{
			execute(s, "3");
			if (i > 0 && s->atop->val > s->atop->next->val)
				execute(s, "1");
		}
		else if (move >= 4 && now->val < start + move)
		{
			execute(s, "6");
			// if (i > 0 && s->btop->val < s->btop->next->val)
			// 	execute(s, "2");
		}
		else
			execute(s, "35");
		now = next;
		i++;
	}
	sort_short(s, mb, ATOP);
	if (move >= 4)
	{
		mergesort_abot(s, start + move, end - mb); //b
		mergesort_bbot(s, start, start + move - 1); // s
	}
	else
		mergesort_abot(s, start, end - mb); //b
}

void	mergesort_abot(t_stack *s, unsigned int start, unsigned int end)
{
	int mb;//mostbig
	int len;
	int move;
	int	i;
	t_node	*now, *next;


	len = end - start + 1;
	mb = 4;
	if (len & 1)
		mb = 3;
	if (len <= 4)
	{
		sort_short(s, len, ABOT);
		// print_mb(mb, end - mb + 1);
		return ;
	}
	move = (len - mb) >> 1;
	i = 0;
	now = s->abot;
	printf("%smergesort ABOT : start %d, end %d, len %d, mb %d\n\033[0m", C_PINK, start, end, len, mb);
	print_queue_ab(s);
	while (i < len)
	{
		if (now == NULL)
		{
			// pri_callerr("merge_a_bottom");
		}
		next = now->prev;
		if (now->val > end - mb)
		{
			// printf("\n%d : mb---- >> ra\n", now->val);//mb
			execute(s, "7");
			if (i > 0 && s->atop->val > s->atop->next->val)
				execute(s, "1");
		}
		else if (move >= 4 && now->val < start + move) //s
			execute(s, "746");
		else //b
		{
			execute(s, "74");//rra, pb BTOP
			// if (i > 0 && s->btop->val < s->btop->next->val)
			// 	execute(s, "2");
		}
		now = next;
		i++;
	}
	sort_short(s, mb, ATOP);
	// print_mb(mb, end - mb + 1);
	if (move >= 4)
	{
		mergesort_btop(s, start + move, end - mb); //b
		mergesort_bbot(s, start, start + move - 1); // s
	}
	else
		mergesort_btop(s, start, end - mb); //b
}

void	mergesort_bbot(t_stack *s, unsigned int start, unsigned int end)
{
	int mb;//mostbig
	int len;
	int move;
	int	i;
	t_node	*now, *next;

	len = end - start + 1;
	mb = 4;
	if (len & 1)
		mb = 3;
	printf("%smergesort BBOT : start %d, end %d, len %d, mb %d\n\033[0m", C_PINK, start, end, len, mb);
	print_queue_ab(s);
	if (len <= 4)
	{
		sort_short(s, len, BBOT);
		return ;
	}
	move = (len - mb) >> 1;
	i = 0;
	now = s->bbot;
	while (i < len)
	{
		next = now->prev;
		if (now->val > end - mb)
		{
			execute(s, "83");
			if (i > 0 && s->atop->val > s->atop->next->val)
				execute(s, "1");
		}
		else if (move >= 4 && now->val < start + move)
			execute(s, "8");
		else
		{
			execute(s, "835");
		}
		now = next;
		i++;
	}
	sort_short(s, mb, ATOP);
	if (move >= 4)
	{
		mergesort_abot(s, start + move, end - mb); //b
		mergesort_btop(s, start, start + move - 1); // s
	}
	else
		mergesort_abot(s, start, end - mb); //b
	// printf("%smergesort ABOT : start %d, end %d, len %d, mb %d, move %d\n\033[0m", C_PINK, start, end, len, mb, move);
	// print_queue_ab(s);
}

// void	get_mostbig(t_node *n, int len, int pivot[])
// {
// 	int max[4];
// 	int i;
// 	i = 0;
// 	while (i < 4)
// 		max[i] = 0;

// 	while (len > 0 && node->next)
// 	{
// 		while (i < 4)
// 		{
// 			if (max[i] < node->next)
// 			{
// 				i = 
// 				while (i < 3)
// 				{
// 					max[i]
// 				}
// 			} 
// 		}

// 	}
// }
