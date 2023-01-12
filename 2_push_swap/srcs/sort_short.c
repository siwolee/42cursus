/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:32:05 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/12 21:52:55 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_short(t_stack *s, int size, char ab)
{
	if (ab == ATOP && pri_sort(s, size, ab))
		return ;
	if (size == 2)
		sort_two(s, ab);
	else if (size == 3)
		sort_three(s, ab);
	else if (size == 4)
		(sort_four(s, ab));

	printf("\033[31msort_short :: %d\n%s", size, C_RS);
	print_queue_ab(s);
}

void	sort_two(t_stack *s, char ab)
{
	if (ab == ATOP)
		return (sort_two_atop(s, s->atop->val, s->atop->next->val));
	else if (ab == BTOP)
		return (sort_two_btop(s, s->btop->val, s->btop->next->val));
	else if (ab == ABOT)
		return (sort_two_abot(s, s->abot->val, s->abot->prev->val));
	else
		return (sort_two_bbot(s, s->bbot->val, s->bbot->prev->val));
}

void	sort_two_atop(t_stack *s, unsigned int a, unsigned int b)
{
	if (a > b)
		sa(s);
}

void	sort_two_btop(t_stack *s, unsigned int a, unsigned int b)
{
	pa(s);
	pa(s);
	if (b > a)
		sa(s);
}

void	sort_two_abot(t_stack *s, unsigned int a, unsigned int b)
{
	rra(s);
	rra(s);
	if (b > a)
		sa(s);
}

void	sort_two_bbot(t_stack *s, unsigned int a, unsigned int b)
{
	rrb(s);
	rrb(s);
	if (a > b)
		sb(s);
	pa(s);
	pa(s);
}

void	get_max_idx(t_stack *s, unsigned int val[4], char ab)
{
	t_node *a;
	unsigned int max;
	int i;

	i = 0;
	a = get_top(s, ab);
	max = a->val;
	while (++i < 4)
	{
		if (ab <= BTOP)
			a = a->next;
		else
			a = a->prev;
		if (max < a->val)
		{
			val[0] = i;
			val[i] = max;
			max = a->val;
		}
		else
			val[i] = a->val;
	}
	printf("get_max_idx%d %d %d %d\n", val[0], val[1], val[2], val[3]);
}

void	sort_four(t_stack *s, char ab)
{
	unsigned int	val[4];

	get_max_idx(s, val, ab);
	if (ab == ATOP)
		return (sort_four_atop(s, val));
	else if (ab == BTOP)
		return (sort_four_btop(s, val));
	else if (ab == ABOT)
		return (sort_four_abot(s, val));
	else
		return (sort_four_bbot(s, val));
}

void	sort_four_atop(t_stack *s, unsigned int val[])
{
	unsigned int	i;

	i = 0;
	if (val[0] == 3)
		return (sort_three_atop(s, val[1], val[2], val[3]));
	while (i < 4 && i >= 0)
	{
		if (val[0] == i)
			ra(s);
		else
			pb(s);
		i++;
	}
	sort_three_btop(s, val[3], val[2], val[1]);
	rra(s);
}

void	sort_four_btop(t_stack *s, unsigned int val[])
{
	unsigned int	i;

	i = 0;
	if (val[0] == 3)
	{
		pa(s);
		return (sort_three_btop(s, val[1], val[2], val[3]));
	}
	while (i < 4 && i >= 0)
	{
		if (val[0] == i)
			pa(s);
		else
			rb(s);
		i++;
	}
	rrb(s);
	rrb(s);
	rrb(s);
	return (sort_three_btop(s, val[1], val[2], val[3]));
}

void	sort_four_abot(t_stack *s, unsigned int val[])
{
	unsigned int	i;

	i = 0;
	if (val[0] == 3)
	{
		rra(s);
		rra(s);
		rra(s);
		rra(s);
		return (sort_three_atop(s, val[3], val[2], val[1]));
	}
	while (i < 4 && i >= 0)
	{
		rra(s);
		if (val[0] != i)
			pb(s);
		i++;
	}
	sort_three_btop(s, val[3], val[2], val[1]);
}

void	sort_four_bbot(t_stack *s, unsigned int val[])
{
	unsigned int	i;

	i = 0;
	if (val[0] == 3)
	{
		rrb(s);
		pa(s);
		rrb(s);
		rrb(s);
		rrb(s);
		return (sort_three_btop(s, val[3], val[2], val[1]));
	}
	while (i < 4 && i >= 0)
	{
		rrb(s);
		if (val[0] == i)
			pa(s);
		i++;
	}
	sort_three_btop(s, val[3], val[2], val[1]);
}


void	sort_three(t_stack *s, char ab)
{
	t_node *a;
	t_node *b;
	t_node *c;

	a = get_top(s, ab);
	if (ab <= BTOP)
	{
		b = a->next;
		c = b->next;
	}
	else
	{
		b = a->prev;
		c = b->prev;
	}
	return (sort_three_ab(s, a->val, b->val, c->val, ab));
}

void	sort_three_ab(t_stack *s, int a, int b, int c, char ab)
{
	if (ab == ATOP)
		sort_three_atop(s, a, b, c);
	else if (ab == BTOP)
		sort_three_btop(s, a, b, c);
	else if (ab == ABOT)
	{
		rra(s);
		rra(s);
		rra(s);
		sort_three_atop(s, c, b, a);
	}
	else
	{
		rrb(s);
		rrb(s);
		rrb(s);
		sort_three_btop(s, c, b, a);
	}
}

void	sort_three_atop(t_stack *s, unsigned int a, unsigned int b, unsigned int c)
{
	if (a < b && b < c)
		return ;
	if (s->atop->val > s->atop->next->val)
		sa(s);
	if (c < a || c < b)
		ra(s);
	if (s->atop->val > s->atop->next->val)
		sa(s);
	if (c < a || c < b)
		rra(s);
	if (s->atop->val > s->atop->next->val)
		sa(s);
}

void	sort_three_btop(t_stack *s, unsigned int a, unsigned int b, unsigned int c)
{
	if (b > a)
		sb(s);
	pa(s);
	if (s->btop->val < s->btop->next->val)
		sb(s);
	pa(s);
	if (s->atop->val > s->atop->next->val)
		sa(s);
	pa(s);
	if (s->atop->val > s->atop->next->val)
		sa(s);
	c = 0;
}

// void	get_max_idx_5(t_stack *s, unsigned int val[5], char ab)
// {
// 	t_node *a;
// 	unsigned int max[2];
// 	int i;

// 	max[0] = 0;
// 	a = get_top(s, ab);
// 	i = 0;
// 	while (++i < 5)
// 	{
// 		val[i] = a->val;
// 		if (max[0] < val[i])
// 		{
// 			max[1] = i;
// 			max[0] = val[i];
// 		}
// 		if (ab <= BTOP)
// 			a = a->next;
// 		else
// 			a = a->prev;
// 	}
// 	val[5] = max[1];
// }

// void	sort_five(t_stack *s, char ab)
// {
// 	unsigned int	val[5];

// 	get_max_idx_5(s, val, ab);
// 	if (ab == ATOP)
// 	{
// 		while (i < 3 && i >= 0)
// 		{
// 			rrb(s);
// 			if (val[4] == i)
// 				pa(s);
// 		}
// 		return (sort__atop(s, val));
// 	}
// 	else if (ab == BTOP)
// 		return (sort_four_btop(s, val));
// 	else if (ab == ABOT)
// 		return (sort_four_abot(s, val));
// 	else
// 		return (sort_four_bbot(s, val));
// }

// void	sort_five_atop(t_stack s, unsigned int val[], char ab);
// {
// 	unsigned int i;

// 	if (val[5] == 4)
// 	{
// 		get_max_idx_4(s, val, ab);
// 		return (sort_four_atop(s, val))
// 	}
// 	i = 0;
// 	while (i < 5)
// 	{
// 		rb(s);
// 		if (val[4] == i)
// 			ra(s);
// 	}
// 	return (sort__atop(s, val));
// }