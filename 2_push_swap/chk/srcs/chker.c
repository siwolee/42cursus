/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:10 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/20 14:20:27 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/chker.h"

int main(int ac, char **av)
{
	int	fd;
	int	*res;
	t_stack	s;

	if (ac <= 2)
		return (0);
	pretreat(&s, av + 1, ac - 1);
	chk_execute(&s, fd);
	print_queue_ab(&s);
	if (s.bsize || chk_sorted_final(s, s.size))
		call_err("KO");
	free_stack(res);
}
