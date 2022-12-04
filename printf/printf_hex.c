/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:12:49 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/02 23:19:13 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_itohex_low(int sign, char buf[], long long arg)
{
	char		hex[16]="0123456789abcdef";
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
	while (temp >= 16)
	{
		temp /= 16;
		len++;
	}
	i = len - 1;
	while (i >= 0 && buf[i] != '-')
	{
		buf[i] = hex[arg % 10];
		i--;
		arg /= 10;
	}
	return (len);
}

int	get_itohex_up(int sign, char buf[], long long arg)
{
	char		hex[16]="0123456789ABCDEF";
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
	while (temp >= 16)
	{
		temp /= 16;
		len++;
	}
	i = len - 1;
	while (i >= 0 && buf[i] != '-')
	{
		buf[i] = hex[arg % 10];
		i--;
		arg /= 10;
	}
	return (len);
}

int	print_num_in_hex_low(char *format, int arg)
{
	char	buf[10];
	int		sign;
	int		len;

	sign = 1;
	if (arg == 0)
		return (write(1, "0", 1));
	if (arg == -2147483647 -1)
		return (write(1, "80000000", 8));
	if (arg < 0)
	{
		sign = -1;
		arg *= -1;
	}
	len = get_itohex_low(sign, buf, arg);
	if (format)
		return (print_format(format, buf, len));
	else
		return (write(1, buf, len));
}

int	print_num_in_hex_up(char *format, int arg)
{
	char	buf[10];
	int		sign;
	int		len;

	sign = 1;
	if (arg == 0)
		return (write(1, "0", 1));
	if (arg == -2147483647 -1)
		return (write(1, "8000000", 8));
	if (arg < 0)
	{
		sign = -1;
		arg *= -1;
	}
	len = get_itohex_up(sign, buf, arg);
	if (format)
		return (print_format(format, buf, len));
	else
		return (write(1, buf, len));
}
