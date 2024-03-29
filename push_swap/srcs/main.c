/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:39:19 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/24 19:19:02 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack				s;
	unsigned int		len;

	len = ac - 1;
	if (ac < 2)
		return (0);
	pretreat(&s, av + 1, ac - 1);
	if (!chk_sorted(&s, s.asize))
	{
		free_stack(&s);
		return (0);
	}
	sort_merge(&s, 1, s.asize, ATOP);
	optimization(s.act);
	print_final(&s);
	free_stack(&s);
}
