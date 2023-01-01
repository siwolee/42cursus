/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:57 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/01 22:13:47 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	mergesort_atop(t_stack *s, unsigned int start, unsigned int end)
{
	int mb;//mostbig
	int len;
	int move;
	int	i;
	t_node	*now, *next;

	len = end - start + 1;
	// if (len <= 4)
	// 	return (sort_short(s)); //if not atop, move to atop too
	mb = 4;
	if (len & 1)
		mb = 3;
	move = (len - mb) >> 1;
	i = 0;
	now = s->atop;
	while (i < len)
	{
		next = now->next;
		if (now->val > end - mb)
		{
			printf("\n%d : mb---- >> ra\n", now->val);//mb
			execute(s, 4, -1);
		}
		else if (now->val <= start + move) //s
		{
			printf("\n%d : s----- >> pb, rb\n", now->val);
			execute(s, 3, 5, -1);//pb, rb
		}
		else //b
		{
			printf("\n%d : b----- >> pb\n", now->val);
			execute(s, 3, -1);//pb
		}
		now = next;
		i++;
	}
		//temp
	// mergesort_btop(s, start, start + move); // s
	// mergesort_blow(s, start + move + 1, end - mb); //b
}

// void	mergesort_btop(t_stack *a, t_stack *b, int start, int end)
// {
// 	int mb;//mostbig
// 	int len;
// 	int move;
// 	int	i;
// 	t_node	*now;

// 	len = end - start + 1;
// 	if (len <= 4)
// 		//pa
// 		return (sort_short(s)); //if not atop, move to atop too
// 	mb = 4;
// 	if (len & 1)
// 		mb = 3;
// 	move = (len - mb) >> 1;
// 	i = 0;
// 	now = s->atop;
// 	while (i < len)
// 	{
// 		if (now->val > end - mb) //mb
// 			//pa
// 		else if (now->val <= start + move) //s
// 			//rb
// 		else //b
// 			//pa,ra
// 		now = now->next;
// 	}
// 	//temp
// 	print_stacks(s);
// 	mergesort_blow(s, start, start + move);//s
// 	mergesort_alow(s, start + move + 1, end - mb);
// }

// void	mergesort_alow(t_stack *a, t_stack *b, int start, int end)
// {
// 	int mb;//mostbig
// 	int len;
// 	int move;
// 	int	i;
// 	t_node	*now;

// 	len = end - start + 1;
// 	if (len <= 4)
// 		//ra
// 		return (sort_short(s)); //if not atop, move to atop too
// 	mb = 4;
// 	if (len & 1)
// 		mb = 3;
// 	move = (len - mb) >> 1;
// 	i = 0;
// 	now = s->atop;
// 	while (i < len)
// 	{
// 		if (now->val > end - mb) //mb
// 			//ra
// 		else if (now->val <= start + move) //s
// 			//ra, pb,pa
// 		else //b
// 			//ra,pb
// 		now = now->next;
// 	}
// 	//temp
// 	print_stacks(s);
// 	mergesort_blow(s, start, start + move);
// 	mergesort_btop(s, start + move + 1, end - mb);
// }

// void	mergesort_blow(t_stack *a, t_stack *b, int start, int end)
// {
// 	int mb;//mostbig
// 	int len;
// 	int move;
// 	int	i;
// 	t_node	*now;

// 	len = end - start + 1;
// 	if (len <= 4)
// 		//ssa reverse, rb, pa
// 		return (sort_short(s)); //if not atop, move to atop too
// 	mb = 4;
// 	if (len & 1)
// 		mb = 3;
// 	move = (len - mb) >> 1;
// 	i = 0;
// 	now = s->atop;
// 	while (i < len)
// 	{
// 		if (now->val > end - mb) //mb
// 			//rb, pa
// 		else if (now->val <= start + move) //s
// 			//rb
// 		else //b
// 			//rb, pa, ra
// 		now = now->next;
// 	}
// 	//temp
// 	print_stacks(s);
// 	mergesort_btop(s, start, start + move);
// 	mergesort_blow(s, start + move + 1, end - mb);
// }