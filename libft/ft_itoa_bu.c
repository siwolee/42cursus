/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haecho <haecho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/17 12:30:41 by haecho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
len = 5, ptr ="-123", where = 1, c = 2
첫 카피 끝나면 "-\0"
2카피 끝나면 "-\0123\0" > res + where(1) + 1, ptr + where부터 시작, len = 3+ 1 =  len - where(1) + 1
마지막에 c를 where에 배치
*/

char	*realloc_n_new_char(char *ptr, int len, char c, int where)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (ptr == 0)
		res[len] = 0;
	else
	{
		ft_strlcpy(res, ptr, where + 1);
		ft_strlcpy(res + where + 1, ptr + where, len - where + 1);
		free(ptr);
	}
	res[where] = c;
	return (res);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	int		where;

	where = 0;
	res = realloc_n_new_char(0, 1, 0, 0);
	if (n == -2147483648)
	{
		res = realloc_n_new_char(res, 11, '0', 0);
		if (!res)
			return (0);
		res = "-2147483648";
		return (res);
	}
	else if (n < 0)
	{
		res[0] = '-';
		n *= -1;
		where = 1;
	}
	len = where;
	while (n != 0)
	{
		len++;
		res = realloc_n_new_char (res, len, n % 10 + '0', where);
		n /= 10;
	}
	return (res);
}