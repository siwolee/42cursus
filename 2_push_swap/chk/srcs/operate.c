/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:17:10 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/08 23:58:27 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chker.h"
#include <stdarg.h>

// void	add_act(char *act,char *newact)
// {
// 	static int	len;
// 	int			i;

// 	i = 0;
// 	while (len < ACTMAX && new*act != 0)
// 	{
// 		act[len] = new*act;
// 		len++;
// 		i++;
// 	}
// 	if (len == ACTMAX)
// 	{
// 		newact(act);
// 		len = 0;
// 	}
// 	if (new*act == 0)
// 	{
// 		act[len] = 0;
// 	}
// }

//실제 실행 및 프린트 함수
void	execute(t_stack *s, char *act)
{
	static int cnt;

	// if (!s)
	// {
	// 	printf("total cnt : %d\n", cnt);
	// 	return ;
	// }
	while (*act != 0)
	{
		cnt++;
		if (*act == '1')
			sa(s);
		else if (*act == '2')
			sb(s);
		else if (*act == '3')
			pa(s);
		else if (*act == '4')
			pb(s);
		else if (*act == '5')
			ra(s);
		else if (*act == '6')
			rb(s);
		else if (*act == '7')
			rra(s);
		else if (*act == '8')
			rrb(s);
		else
		{
			cnt--;
			return ;
		}
		act++;
	}
}
