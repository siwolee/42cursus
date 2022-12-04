/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:12:43 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/04 17:09:05 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
	else if (*type == 'd')
		return (print_integer(format, va_arg(*arg_ptr, int)));
	else if (*type == 'i')
		return (print_integer(format, va_arg(*arg_ptr, int)));
	else if (*type == 'u')
		return (print_unsigened_int(format, va_arg(*arg_ptr, unsigned int)));
	else if (*type == 'x')
		return (print_num_in_hex_low(format, va_arg(*arg_ptr, int)));
	else if (*type == 'X')
		return (print_num_in_hex_up(format, va_arg(*arg_ptr, int)));
	else
		return (0);
}
// void	print_escape(char c)
// {
// 	if (c == '\\')
// 		ft_putchar('\\');
// 	else if (c == 'a')
// 		ft_putchar('\a');
// 	else if (c == 'b')
// 		ft_putchar('\b');
// 	else if (c == 'f')
// 		ft_putchar('\f');
// 	else if (c == 'n')
// 		ft_putchar('\n');
// 	else if (c == 'r')
// 		ft_putchar('\r');
// 	else if (c == 't')
// 		ft_putchar('\t');
// 	else if (c == 'v')
// 		ft_putchar('\v');
// 	else if (c == '\'')
// 		ft_putchar('\'');
// }
