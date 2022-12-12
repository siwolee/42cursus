/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:04:03 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/12 13:26:12 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *buf, ...)
{
	int		i;
	va_list	arg_ptr;
	int		len;

	if (!buf)
		return (-1);
	i = 1;
	va_start(arg_ptr, buf);
	i = 0;
	len = 0;
	while (buf[i])
	{
		if (buf[i] == '%')
			len += print_type((char *)buf + ++i, &arg_ptr);
		else
		{
			ft_putchar(buf[i]);
			len += 1;
		}
		i++;
	}
	va_end(arg_ptr);
	return (len);
}
