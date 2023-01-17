/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:33:33 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 13:31:11 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_mb(int mb, int min)
{
	static int cnt;

	cnt += mb;
	printf("^^^^ mbcnt : %d, min: %d ^^^^^^^^^^^\n", cnt, min);
}

void	pri_callerr(char *name)
{
	printf("%sError exit : %s\n%s",C_RED, name, C_RS);
	exit(0);
}

int	pri_all_sort(t_stack *s, int len)
{
	int		i;
	unsigned int		bf;
	t_node	*n;

	if (s->btop || !s->atop)
		return (1);
	i = 0;
	n = s->atop;
	bf = s->atop->val;
	while (n->next)
	{
		n = n->next;
		if (!(n->val == bf + 1))
		{
			printf("error-> %d %d \n", bf, n->val);
			return (1);
		}
		bf = n->val;
		i++;
	}
	printf("GOOD\n");
	if (i == len)
		return (0);
	else
		return (1);
}

int	pri_sort(t_stack *s, int len, char ab)
{
	int		i;
	unsigned int		bf;
	t_node	*n;

	i = 0;
	n = s->atop;
	bf = s->atop->val;
	if (ab == ATOP || ab == BTOP)
	{
		while (n->next)
		{
			n = n->next;
			if (bf >= n->val)
				break ;
			bf = n->val;
			i++;
		}
	}
	else if (ab == ABOT || ab == BBOT)
	{
		while (n->prev)
		{
			n = n->prev;
			if (bf >= n->val)
				break ;
			bf = n->val;
			i++;
		}
	}
	if (i == len)
		return (1);
	else
		return (0);
}