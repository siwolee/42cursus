/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_chk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:39:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/24 19:24:29 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	read_execute(t_stack *s);
int		chk_execute(t_stack *s, char *x);
int		ft_strncmp(char *s1, char *s2);

int	main(int ac, char **av)
{
	t_stack	s;

	if (ac < 2)
		return (0);
	pretreat(&s, av + 1, ac - 1);
	read_execute(&s);
	if (s.bsize > 0 || chk_sorted_final(&s))
		call_err(&s, "KO");
	free_stack(&s);
	ft_printf("OK\n");
}

void	read_execute(t_stack *s)
{
	char	*x;
	int		flag;

	x = get_next_line(0);
	flag = 0;
	while (x)
	{
		if (chk_execute(s, x))
		{
			flag = 1;
		}
		free(x);
		x = get_next_line(0);
	}
	free(x);
	if (flag)
		call_err(s, "Error");
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	chk_execute(t_stack *s, char *x)
{
	if (ft_strcmp(x, "sa\n") == 0)
		sa(s);
	else if (ft_strcmp(x, "sb\n") == 0)
		sb(s);
	else if (ft_strcmp(x, "pa\n") == 0)
		pa(s);
	else if (ft_strcmp(x, "pb\n") == 0)
		pb(s);
	else if (ft_strcmp(x, "ra\n") == 0)
		ra(s);
	else if (ft_strcmp(x, "rb\n") == 0)
		rb(s);
	else if (ft_strcmp(x, "rra\n") == 0)
		rra(s);
	else if (ft_strcmp(x, "rrb\n") == 0)
		rrb(s);
	else if (ft_strcmp(x, "ss\n") == 0)
		ss(s);
	else if (ft_strcmp(x, "rr\n") == 0)
		rr(s);
	else if (ft_strcmp(x, "rrr\n") == 0)
		rrr(s);
	else
		return (1);
	return (0);
}
