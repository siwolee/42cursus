/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:55:06 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/16 13:46:16 by siwolee          ###   ########.fr       */
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
	unsigned int		len;
	// unsigned int pivot[2];

	len = ac - 1;
	if (ac <= 2)
		return (0);
	pretreat(&s, av + 1, ac - 1);
	// pb(&s);
	// pb(&s);
	// pb(&s);
	// pb(&s);
	sort_merge4(&s, 1, len, ATOP);
	optimization(s.act);
	print_final(&s);
	print_queue_ab(&s);
	
	pri_all_sort(&s, ac - 1);
	free_stack(&s);
}
