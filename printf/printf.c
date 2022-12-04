/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:04:03 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/04 18:18:01 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *buf, ...)
{
	int		i;
	va_list	arg_ptr;
	char	*bbuf;
	int		len;

	if (!buf)
		return (-1);
	i = 1;
	bbuf = (char *)buf;
	va_start(arg_ptr, buf);
	i = 0;
	len = 0;
	while (bbuf[i])
	{
		if (bbuf[i] == '%')
			len += print_type(bbuf + ++i, &arg_ptr);
		else
		{
			ft_putchar(bbuf[i]);
			len += 1;
		}
		i++;
	}
	va_end(arg_ptr);
	return (len);
}
