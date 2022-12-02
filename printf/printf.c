/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:04:03 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/01 23:30:56 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *buf, ...)
{
	int		i;
	va_list	arg_ptr;
	char	*bbuf;
	// char	*format;

	i = 1;
	bbuf = (char *)buf;
	va_start(arg_ptr, buf);
	i = 0;
	while (bbuf[i])
	{
		if (bbuf[i] == '%')
			arg_ptr = print_type(bbuf + ++i, arg_ptr);
		else if (bbuf[i] == '\\')
			print_escape(bbuf[++i]);
		else
			ft_putchar(bbuf[i]);
		i++;
	}
	va_end(arg_ptr);
	return (0);
}

#include <stdio.h>

int main()
{
	char c = '^';
	char *str1 = "Hallp, vo ist die mes?";
	
	printf("::: char test :::\n");
	printf("original  : %c\n", c);
	ft_printf("ft_printf : %c\n", c);

	printf("\n\n::: escape test :::\n");
	printf("original  : \a\b\f\n\r\t\v\'\\ :\n");
	ft_printf("***ft_printf :\a\b\f\n\r\t\v\'\\ :\n"); //마지막 \\랑 공백이 안나오고 있음

	printf("\n\n::: string test :::\n");
	printf("original  : %s\n", str1);
	ft_printf("ft_printf : %s\n", str1);

	printf("\n\n::: pointer test :::\n");
	printf("original  : %p %p\n", str1, &c);
	ft_printf("ft_printf : %p %p\n", str1, &c);
	printf("original  : %p %p\n", -1, 1);
	ft_printf("ft_printf : %p %p\n", -1, 1);
}