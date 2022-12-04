/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:12:49 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/04 16:47:46 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_itohex_low(char buf[], long long arg)
{
	char		*hex;
	int			len;
	int			i;
	long long	temp;

	hex = "0123456789abcdef";
	len = 1;
	temp = arg;
	while (temp >= 16)
	{
		temp /= 16;
		len++;
	}
	i = len - 1;
	while (i >= 0)
	{
		buf[i] = hex[arg % 16];
		i--;
		arg /= 16;
	}
	return (len);
}

int	get_itohex_up(char buf[], long long arg)
{
	char		*hex;
	int			len;
	int			i;
	long long	temp;

	hex = "0123456789ABCDEF";
	len = 1;
	temp = arg;
	while (temp >= 16)
	{
		temp /= 16;
		len++;
	}
	i = len - 1;
	while (i >= 0)
	{
		buf[i] = hex[arg % 16];
		i--;
		arg /= 16;
	}
	return (len);
}

int	print_num_in_hex_low(char *format, int arg)
{
	char			buf[10];
	int				len;
	unsigned int	uarg;

	if (arg == 0)
		return (write(1, "0", 1));
	uarg = (unsigned int)arg;
	len = get_itohex_low(buf, uarg);
	if (format)
		return (print_format(format, buf, len));
	else
		return (write(1, buf, len));
}

int	print_num_in_hex_up(char *format, int arg)
{
	char			buf[10];
	int				len;
	unsigned int	uarg;

	if (arg == 0)
		return (write(1, "0", 1));
	if (arg == -2147483647 - 1)
		return (write(1, "80000000", 8));
	uarg = (unsigned int)arg;
	len = get_itohex_up(buf, uarg);
	if (format)
		return (print_format(format, buf, len));
	else
		return (write(1, buf, len));
}
