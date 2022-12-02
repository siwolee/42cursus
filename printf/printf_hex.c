/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:12:49 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/02 22:37:57 by siwolee          ###   ########.fr       */
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
		buf[i] = arg % 10 + '0'];
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
		return (write(1, "-2147483648", 11));
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
	char 	*hex = "0123456789ABCDEF";
	char 	res[20];
	size_t	ptr2;
	int		size;
	int		i;

	i = 0;
	if (ptr2 == 0)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	while (ptr2)
	{
		res[i] = hex[ptr2 % 16];
		ptr2 /= 16;
		i++;
	}
	size = i + 2;
	while (i > 0)
	{
		i--;
		ft_putchar(res[i]);
	}
	format = 0;
	return (size);
}
