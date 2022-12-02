/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:37:09 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/02 21:05:47 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_itoa(int sign, char buf[], long long arg)
{
	int			len;
	int			i;
	long long	temp;

	len = 1;
	temp = arg;
	if (sign == -1)
	{
		len++;
		buf[0] = '-';
	}
	while (temp >= 10)
	{
		temp /= 10;
		len++;
	}
	i = len - 1;
	while (i >= 0 && buf[i] != '-')
	{
		buf[i] = arg % 10 + '0';
		i--;
		arg /= 10;
	}
	return (len);
}

int	print_integer(char *format, int arg)
{
	char	buf[12];
	int		sign;
	int		len;

	sign = 1;
	if (arg == 0)
		return (write(1, "0", 1));
	if (arg == -2147483647 -1)
		return (write(1, "-2147483648", 11));
	if (arg < 0)
	{
		sign = -1;
		arg *= -1;
	}
	len = get_itoa(sign, buf, arg);
	if (format)
		return (print_format(format, buf, len));
	else
		return (write(1, buf, len));
}

int		print_unsigened_int(char *format, unsigned int arg)
{
	char	buf[20];
	int		len;

	if (arg == 0)
		return (write(1, "0", 1));
	len = get_itoa(1, buf, arg);
	if (format)
		return (print_format(format, buf, len));
	else
		return (write(1, buf, len));
}