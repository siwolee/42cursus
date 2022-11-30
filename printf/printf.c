/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:04:03 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/29 21:58:23 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *buf, ...)
{
	int		i;
	va_list	arg_list;
	int		arg_num;

	i = 1;
	while (buf[i])
	{
		if (buf[i - 1] == '%' && buf[i] != '%')
			arg_num++;
	}
	va_start(arg_list, arg_num);
	while (buf[i])
	{
		if (buf[i] == '%')
			print_type((char)buf[++i], arg_list);
		else if (buf[i] == '\\')
			print_escape((char)buf[++i]);
		else
			putchar(buf[i]);
		i++;
	}
}

#include <stdio.h>
int main()
{
	char c = '^';
	
	printf("::: char test :::\n");
	printf("original : %c", c);
	ft_printf("ft_printf : %c", c);
}