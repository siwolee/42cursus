/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:33:33 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/19 19:15:10 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_mb(int mb, int min)
{
	static int	cnt;

	cnt += mb;
	ft_printf("^^^^ mbcnt : %d, min: %d ^^^^^^^^^^^\n", cnt, min);
}

void	call_err(char *name)
{
	ft_printf("%s\n", name);
	exit(0);
}

int	chk_sorted_final(t_stack *s, int len)
{
	int				i;
	unsigned int	bf;
	t_node			*n;

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
			ft_printf("error-> %d %d \n", bf, n->val);
			return (1);
		}
		bf = n->val;
		i++;
	}
	ft_printf("GOOD\n");
	if (i == len)
		return (0);
	else
		return (1);
}

int	chk_sorted(t_stack *s, int len)
{
	int				i;
	unsigned int	bf;
	t_node			*n;

	i = 0;
	n = s->atop;
	bf = s->atop->val;
	while (n->next)
	{
		n = n->next;
		if (bf >= n->val)
			break ;
		bf = n->val;
		i++;
	}
	if (i == len)
		return (1);
	else
		return (0);
}
