/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:04:03 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/20 16:04:12 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *buf, ...)
{
	int		i;
	va_list	arg_ptr;
	int		len;
	int		total_len;

	if (!buf)
		return (-1);
	va_start(arg_ptr, buf);
	i = 0;
	total_len = 0;
	while (buf[i])
	{
		if (buf[i] == '%')
			len = print_type((char *)buf + ++i, &arg_ptr);
		else
			len = ft_putchar(buf[i]);
		if (len == -1)
			return (-1);
		total_len += len;
		i++;
	}
	va_end(arg_ptr);
	return (total_len);
}

int	print_type(char *type, va_list *arg_ptr)
{
	char	*format;

	if (*type == '%')
		return (write(1, "%%", 1));
	format = NULL;
	type = get_format(&format, type);
	if (*type == 'c')
		return (print_char(format, va_arg(*arg_ptr, int)));
	else if (*type == 's')
		return (print_string(format, va_arg(*arg_ptr, char *)));
	else if (*type == 'p')
		return (print_pointer(format, va_arg(*arg_ptr, void *)));
	else if (*type == 'd' || *type == 'i')
		return (print_integer(format, va_arg(*arg_ptr, int)));
	else if (*type == 'u')
		return (print_unsigened_int(format, va_arg(*arg_ptr, unsigned int)));
	else if (*type == 'X' || *type == 'x')
		return (print_num_in_hex(format, va_arg(*arg_ptr, int), *type));
	else
		return (0);
}

int	ft_putchar(char *format, char arg)
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
