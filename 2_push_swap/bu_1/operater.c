/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:17:10 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/01 17:14:38 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdarg.h>
//실제 실행 및 프린트 함수
int	execute(t_stack *a, t_stack *b, ...)
{
	static int cnt;
	va_list	arg;
	int		act;

	va_start(arg, b);
	while ((act = va_arg(arg, int)) >= 0)
	{
		cnt++;
		if (act == 0)
			sa(a);
		else if (act == 1)
			sb(b);
		else if (act == 2)
			pa(a, b);
		else if (act == 3)
			pb(a, b);
		else if (act == 4 && a->bot)
			ra(a);
		else if (act == 5 && b->bot)
			rb(b);
		else if (act == 6)
			rra(a);
		else if (act == 7)
			rrb(b);
		print_stacks(a, b);
	}
	va_end(arg);
	return (1);
}