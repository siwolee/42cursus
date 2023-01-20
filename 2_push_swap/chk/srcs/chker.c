/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:10 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/20 14:33:27 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/chker.h"

int main(int ac, char **av)
{
	int	fd;
	int	*res;
	t_stack	s;

	if (ac < 2)
		return (0);
	res = malloc(sizeof(int) * (ac -1));
	if (!res)
		return (0);
	atoi_arr(ac -1, av + 1, res);
	init_stack(&s, res, ac -1);
	print_queue_ab(&s);
	fd  = 0;
	if (chk_execute(&s, fd))
	{
		printf("KO");
		printf("error: exec\n");
		return (1);
	}
	print_queue_ab(&s);
	if (chk_sort(&s, ac - 1))
	{
		printf("KO\n");
		printf("error: sort\n");
		execute(NULL, NULL);
		return (1);
	}
	free_stack(&s);
}
