/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:17:10 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 13:30:18 by siwolee          ###   ########.fr       */
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

t_act	*init_act()
{
	t_act	*next;

	next = malloc(sizeof(t_act));
	if (!next)
		pri_callerr("malloc");
	ft_bzero(next->arr, ACTMAX);
	next->next = NULL;
	return (next);
}

t_act	*add_act(t_act *act)
{
	t_act	*next;

	next = malloc(sizeof(t_act));
	if (!next)
		pri_callerr("malloc");
	ft_bzero(next->arr, ACTMAX);
	next->next = NULL;
	act->next = next;
	return (next);
}

void	add_act_len(t_act *act,char newact)
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

void	print_final(t_stack *s)
{
	int	i;
	int	cnt;
	t_act	*act;

	cnt = 0;
	act = s->act;
	while (act)
	{
		i = 0;
		while (s->act->arr[i] != 0 && i < ACTMAX)
		{
			if (s->act->arr[i] > 90)
			{
				if (s->act->arr[i] == SS)
					printf("ss\n");
				else if (s->act->arr[i] == RR)
					printf("rr\n");
				else if (s->act->arr[i] == RRR)
					printf("rrr\n");
				i++;
			}
			else if (s->act->arr[i] == '1')
				printf("sa\n");
			else if (s->act->arr[i] == '2')
				printf("sb\n");
			else if (s->act->arr[i] == '3')
				printf("pa\n");
			else if (s->act->arr[i] == '4')
				printf("pb\n");
			else if (s->act->arr[i] == '5')
				printf("ra\n");
			else if (s->act->arr[i] == '6')
				printf("rb\n");
			else if (s->act->arr[i] == '7')
				printf("rra\n");
			else if (s->act->arr[i] == '8')
				printf("rrb\n");
			i++;
			cnt++;
		}
		act = act->next;
	}
	// printf("total cnt : %d\n", cnt);
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

// void	print_act(t_act *act)
// {
// 	int	i;
// 	int	cnt;

// 	cnt = 0;
// 	while (act)
// 	{
// 		i = 0;
// 		while (act->arr[i] != 0 && i < ACTMAX)
// 		{
// 			if (act->arr[i] == '1')
// 				printf("sa\n");
// 			else if (act->arr[i] == '2')
// 				printf("sb\n");
// 			else if (act->arr[i] == '3')
// 				printf("pa\n");
// 			else if (act->arr[i] == '4')
// 				printf("pb\n");
// 			else if (act->arr[i] == '5')
// 				printf("ra\n");
// 			else if (act->arr[i] == '6')
// 				printf("rb\n");
// 			else if (act->arr[i] == '7')
// 				printf("rra\n");
// 			else if (act->arr[i] == '8')
// 				printf("rrb\n");
// 			else
// 				printf("error : %c\n", act->arr[i]);
// 			i++;
// 			cnt++;
// 		}
// 		act = act->next;
// 	}
// }

void	optimization(t_act *act)
{
	int	i;
	int	cnt;
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
	else if ((*a == PA && *b == PB) || (*a == PB && *b == PA)
		|| (*a == RA && *b == RRA) || (*a == RRA && *b == RA)
		|| (*a == RB && *b == RRB) || (*a == RRB && *b == RB))
	{
		*a = PASS;
		*b = PASS;
	}
}
