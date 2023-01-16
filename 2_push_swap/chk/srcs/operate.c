/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:17:10 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/16 22:51:44 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/chker.h"
#include <stdarg.h>

void	execute(t_stack *s, char *newact)
{
	while (*newact != 0)
	{
		if (*newact == '1')
			sa(s);
		else if (*newact == '2')
			sb(s);
		else if (*newact == '3')
			pa(s);
		else if (*newact == '4')
			pb(s);
		else if (*newact == '5')
			ra(s);
		else if (*newact == '6')
			rb(s);
		else if (*newact == '7')
			rra(s);
		else if (*newact == '8')
			rrb(s);
		newact++;
	}
}
