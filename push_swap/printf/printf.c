/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:04:03 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/14 15:44:31 by siwolee          ###   ########.fr       */
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
