/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:12:43 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/29 16:19:06 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	putchar(char c)
{
	write(1, &c, 1);
}


void	print_type(char *type, va_list arg_list)
{
	char	*format;
	if (*type == '%')
		putchar('%');
	type = get_format(&format, type);
	if (*type == 'c')
		print_char(format, va_arg(arg_list, char));
	else if (*type == 's')
		print_string(format, va_arg(arg_list, char *));
	else if (*type == 'p')
		print_pointer(format, va_arg(arg_list, void *));
	else if (*type == 'd')
		print_decimal(format, va_arg(arg_list, int));
	else if (*type == 'i')
		print_integer(format, va_arg(arg_list, int));
	else if (*type == 'u')
		print_unsigened_decimal(format, va_arg(arg_list, unsigned int));
	else if (*type == 'x')
		print_num_in_hex_low(format, va_arg(arg_list, int));
	else if (*type == 'X')
		print_num_in_hex_up(format, va_arg(arg_list, int));
}

char	*get_format(char **format, char *type)
{
	int i;

	i = 0;
	while (ft_isalpha(type[i]) != 1)
		i++;
	if (i != 0)
	{
		*format = ((char *)malloc(sizeof(char) * i));
		if (!*format)
			return (0);
		ft_strlcpy(format, type, i);
	}
	else
		*format = 0;
	return (type[i]);
}

void	print_char(char *format, char *type, char arg)
{
	if (format)
		print_format(format, &arg, 1);
	else
		putchar(arg);
}

