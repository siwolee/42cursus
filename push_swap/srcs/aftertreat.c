/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aftertreat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:00:08 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/30 18:57:56 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	call_err(void *s, char *name)
{
	ft_printf("%s\n", name);
	if (s != NULL)
		free_stack(s);
	exit(0);
}

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
	if (c == SA)
		ft_printf("sa\n");
	else if (c == SB)
		ft_printf("sb\n");
	else if (c == PA)
		ft_printf("pa\n");
	else if (c == PB)
		ft_printf("pb\n");
	else if (c == RA)
		ft_printf("ra\n");
	else if (c == RB)
		ft_printf("rb\n");
	else if (c == RRA)
		ft_printf("rra\n");
	else if (c == RRB)
		ft_printf("rrb\n");
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
	else if ((*a == PA && *b == PB) || (*a == PB && *b == PA) || \
			(*a == RA && *b == RRA) || (*a == RRA && *b == RA) || \
			(*a == RB && *b == RRB) || (*a == RRB && *b == RB))
	{
		*a = PASS;
		*b = PASS;
	}
}
