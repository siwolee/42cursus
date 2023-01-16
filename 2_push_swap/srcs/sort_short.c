/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:32:05 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/16 13:23:42 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_short(t_stack *s, int size, char ab)
{
	printf("\033[31msort_short :: %d\n%s", size, C_RS);
	print_queue_ab(s);
	if (ab == ATOP && pri_sort(s, size, ab))
		return ;
	if (size == 2)
		sort_two(s, ab);
	else if (size == 3)
		sort_three(s, ab);
	else if (size == 4)
		(sort_four(s, ab));
}
