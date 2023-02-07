/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:40:32 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/20 16:04:12 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
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
