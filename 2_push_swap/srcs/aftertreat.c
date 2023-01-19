/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aftertreat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:00:08 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/19 19:15:36 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_final(t_stack *s)
{
	int		i;
	int		cnt;
	t_act	*act;

	cnt = 0;
	act = s->act;
	while (act)
	{
		i = 0;
		while (s->act->arr[i] != 0 && i < ACTMAX)
		{
			print_exec(s->act->arr[i]);
			i++;
			cnt++;
		}
		act = act->next;
	}
}

void	print_exec(char c)
{
	if (c == SS)
		ft_printf("ss\n");
	else if (c == RR)
		ft_printf("rr\n");
	else if (c == RRR)
		ft_printf("rrr\n");
	if (c == '1')
		ft_printf("sa\n");
	else if (c == '2')
		ft_printf("sb\n");
	else if (c == '3')
		ft_printf("pa\n");
	else if (c == '4')
		ft_printf("pb\n");
	else if (c == '5')
		ft_printf("ra\n");
	else if (c == '6')
		ft_printf("rb\n");
	else if (c == '7')
		ft_printf("rra\n");
	else if (c == '8')
		ft_printf("rrb\n");
}

void	execute(t_stack *s, char *newact)
{
	while (*newact != 0)
	{
		if (*newact == '1')
			sa(s);
		else if (*newact == '2')
			sb(s);
		else if (*newact == '3')
			pa(s);
		else if (*newact == '4')
			pb(s);
		else if (*newact == '5')
			ra(s);
		else if (*newact == '6')
			rb(s);
		else if (*newact == '7')
			rra(s);
		else if (*newact == '8')
			rrb(s);
		newact++;
	}
}

void	optimization(t_act *act)
{
	int		i;
	int		cnt;
	char	*a;
	char	*b;

	cnt = 0;
	while (act)
	{
		i = 0;
		while (act->arr[i] != 0 && i < ACTMAX)
		{
			a = &(act->arr[i]);
			if (i + 1 == ACTMAX)
				b = &(act->next->arr[0]);
			else
				b = &(act->arr[i + 1]);
			if (b == 0)
				break ;
			chk_double(a, b);
			i++;
			cnt++;
		}
		act = act->next;
	}
}

void	chk_double(char *a, char *b)
{
	if ((*a == SA && *b == SB) || (*a == SB && *b == SA))
	{
		*a = SS;
		*b = PASS;
	}
	else if ((*a == RA && *b == RB) || (*a == RB && *b == RA))
	{
		*a = RR;
		*b = PASS;
	}
	else if ((*a == RRA && *b == RRB) || (*a == RRB && *b == RRA))
	{
		*a = RRR;
		*b = PASS;
	}
	else if ((*a == PA && *b == PB) || (*a == PB && *b == PA) || (*a == RA
			&& *b == RRA) || (*a == RRA && *b == RA) || (*a == RB
			&& *b == RRB) || (*a == RRB && *b == RB))
	{
		*a = PASS;
		*b = PASS;
	}
}
