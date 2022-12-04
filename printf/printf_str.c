/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:40:32 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/04 16:54:15 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char *format, char arg)
{
	if (format)
		return (print_format(format, &arg, 1));
	else
		return (write(1, &arg, 1));
}

int	print_string(char *format, char *str)
{
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	if (format)
		return (print_format(format, str, ft_strlen(str)));
	return (write(1, str, ft_strlen(str)));
}

int	print_pointer(char *format, void *ptr)
{
	char	*hex;
	char	res[20];
	size_t	ptr2;
	int		size;
	int		i;

	hex = "0123456789abcdef";
	ptr2 = (size_t)ptr;
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
	while (i-- > 0)
		ft_putchar(res[i]);
	format = 0;
	return (size);
}
