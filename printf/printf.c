/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:04:03 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/28 13:11:36 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *buf, ...)
{
	size_t i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '%')
			print_type(buf[++i]);
		else if (buf[i] == '\\')
			print_escape(buf[++i]);
		else
			putchar(buf[i]);
		i++;
	}
}

