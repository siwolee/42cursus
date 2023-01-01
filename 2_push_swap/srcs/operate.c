/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:17:10 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/01 23:42:37 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdarg.h>
//실제 실행 및 프린트 함수
int	execute(t_stack *s, ...)
{
	static int cnt;
	va_list	arg;
	int		act;

	va_start(arg, s);
	while ((act = va_arg(arg, int)) >= 0)
	{
		cnt++;
		if (act < 2)
			s_(s, act & 1);
		else if (act < 4)
			p_(s, act & 1);
		else if (act < 6)
			r_(s, act & 1);
		else if (act < 8)
			rr_(s, act & 1);
		print_stacks(s);
	}
	va_end(arg);
	return (1);
}