/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haecho <haecho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/16 18:50:12 by haecho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	int		sign;
	int		n_copy;

	len = 1;
	if (n < 0 && ++len)
		sign = -1;
	n_copy = n;
	while (++len && n_copy / 10 > 10)
		n_copy /= 10;
	res = (char *)malloc(sizeof(char) * (len + 1));
	res[len] = 0;
	while (--len >= 0)
	{
		res[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
