/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:27:49 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 21:01:33 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	get_mostbig_ab(char ab)
{
	if (ab == ATOP)
		return (ABOT);
	else
		return (ATOP);
}

char	get_big_ab(char ab)
{
	if (ab == BTOP)
		return (ABOT);
	else
		return (BTOP);
}

char	get_small_ab(char ab)
{
	if (ab == ATOP || ab == ABOT)
		return (BBOT);
	else if (ab == BTOP)
		return (BBOT);
	else
		return (ABOT);
}
