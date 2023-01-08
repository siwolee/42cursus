/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/08 21:59:49 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>

int	ft_atoi(const char *str)
{
	int		sign;
	int		re;
	size_t	i;

	sign = 1;
	re = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		re = re * 10 + str[i] - '0';
		i++;
	}
	re *= sign;
	return (re);
}
