/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:12:43 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/14 19:13:11 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
