/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:55:06 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/11 13:57:33 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	t_stack	s;
	int		len;

	len = ac - 1;
	if (ac <= 2)
		return (0);
	pretreat(&s, av + 1, ac - 1);
	// print_queue_ab(&s);
	// mergesort_atop(&s, 1, len);
	merge_sort(&s, ATOP, ac - 1, (ac -1) >> 2);
	// optimization(s.act);
	print_final(&s);
	// print_queue_ab(&s);
	pri_all_sort(&s, ac - 1);
	free_stack(&s);
}
