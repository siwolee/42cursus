/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:12:43 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/01 23:26:42 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


va_list	print_type(char *type, va_list arg_ptr)
{
	char	*format;
	if (*type == '%')
		ft_putchar('%');
	type = get_format(&format, type);
	if (*type == 'c')
		print_char(format, va_arg(arg_ptr, int));
	else if (*type == 's')
		print_string(format, va_arg(arg_ptr, char *));
	else if (*type == 'p')
		print_pointer(format, va_arg(arg_ptr, void *));
	// else if (*type == 'd')
	// 	print_decimal(format, va_arg(arg_ptr, int));
	// else if (*type == 'i')
	// 	print_integer(format, va_arg(arg_ptr, int));
	// else if (*type == 'u')
	// 	print_unsigened_decimal(format, va_arg(arg_ptr, unsigned int));
	// else if (*type == 'x')
	// 	print_num_in_hex_low(format, va_arg(arg_ptr, int));
	// else if (*type == 'X')
	// 	print_num_in_hex_up(format, va_arg(arg_ptr, int));
	return (arg_ptr);
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
		ft_strlcpy(*format, type, i);
	}
	else
		*format = 0;
	return (type + i);
}

//temp;;
void	print_format(char *format, char *str, int strlen)
{ //temp
	write(1, str, strlen);
	free(format);
}

void	print_char(char *format, char arg)
{
	if (format)
		print_format(format, &arg, 1);
	else
		ft_putchar(arg);
}

void	print_string(char *format, char *str)
{
	if (format)
	{
		print_format(format, str, ft_strlen(str));
		return ;
	}
	write(1, str, ft_strlen(str));
}

void	print_pointer(char *format, void *ptr)
{
	char 	*hex = "0123456789abcdef";
	char 	res[10];
	size_t	ptr2;
	int		i;

	ptr2 = (size_t)ptr;
	i = 0;
	while (ptr2)
	{
		res[i] = hex[ptr2 % 16];
		ptr2 /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(res[i]);
	}
	format = 0;
}

void	print_escape(char c)
{
	if (c == '\\')
		ft_putchar('\\');
	else if (c == 'a')
		ft_putchar('\a');
	else if (c == 'b')
		ft_putchar('\b');
	else if (c == 'f')
		ft_putchar('\f');
	else if (c == 'n')
		ft_putchar('\n');
	else if (c == 'r')
		ft_putchar('\r');
	else if (c == 't')
		ft_putchar('\t');
	else if (c == 'v')
		ft_putchar('\v');
	else if (c == '\'')
		ft_putchar('\'');
}

