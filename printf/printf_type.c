/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:12:43 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/02 23:23:14 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_type(char *type, va_list arg_ptr)
{
	char	*format;
	int		len;

	if (*type == '%')
		return (write(1, "%%", 1));
	type = get_format(&format, type);
	if (*type == 'c')
		len = print_char(format, va_arg(arg_ptr, int));
	else if (*type == 's')
		len = print_string(format, va_arg(arg_ptr, char *));
	else if (*type == 'p')
		len = print_pointer(format, va_arg(arg_ptr, void *));
	else if (*type == 'd')
		len = print_integer(format, va_arg(arg_ptr, int));
	else if (*type == 'i')
		len = print_integer(format, va_arg(arg_ptr, int));
	else if (*type == 'u')
		len = print_unsigened_int(format, va_arg(arg_ptr, unsigned int));
	else if (*type == 'x')
		len = print_num_in_hex_low(format, va_arg(arg_ptr, int));
	else if (*type == 'X')
		len = print_num_in_hex_up(format, va_arg(arg_ptr, int));
	else
		len = 0;
	return (len);
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

int	print_format(char *format, char *str, int strlen)
{
	write(1, str, strlen);
	free(format);
	return (0);
}

int	print_char(char *format, char arg)
{
	if (format)
		return (print_format(format, &arg, 1));
	else
		return (write(1, &arg, 1));
}

int	print_string(char *format, char *str)
{
	if (format)
		return (print_format(format, str, ft_strlen(str)));
	return (write(1, str, ft_strlen(str)));
}

int	print_pointer(char *format, void *ptr)
{
	char 	*hex = "0123456789abcdef";
	char 	res[20];
	size_t	ptr2;
	int		size;
	int		i;

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
	while (i > 0)
	{
		i--;
		ft_putchar(res[i]);
	}
	format = 0;
	return (size);
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

