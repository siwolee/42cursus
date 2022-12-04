/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:54:19 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/04 17:06:44 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int main()
{
	//char c = '^';
	//char *str1 = "Hallp, vo ist die mes?";
	
	printf("::: char test :::\n");
	printf("original  : \001\002\007\v\010\f\r\n");
	ft_printf("ft_printf : \001\002\007\v\010\f\r\n");

	printf("\n\n::: escape test :::\n");
	printf("original  : \a\b\f\n\r\t\v\'\\ :\n");
	ft_printf("***ft_printf :\a\b\f\n\r\t\v\'\\ :\n"); //마지막 \\랑 공백이 안나오고 있음

	printf("\n\n::: string test :::\n");
	printf("original  : %s\n", "can it handle \t and \n?");
	ft_printf("ft_printf : %s\n", "can it handle \t and \n?");

	printf("\n\n::: string test :::\n");
	printf("original  : %s\n", NULL);
	ft_printf("ft_printf : %s\n", NULL);

	printf("\n\n::: pointer test :::\n");
	printf("original  : %p \n", NULL);
	ft_printf("ft_printf : %p \n",NULL);

	printf("\n\n::: decimal test :::\n");
	printf("original  : %d %d %d %d %d %d \n", 45678, -2147483647 - 1, -1, 0, 200, 2147483647);
	ft_printf("ft_printf : %d %d %d %d %d %d \n", 45678, -2147483647 - 1, -1, 0, 200, 2147483647);

	printf("\n\n::: hex_low test :::\n");
	printf("original  : %x %x %x %x %x\n", -2147483647 - 1, -1, 0, 200, 2147483647);
	ft_printf("ft_printf : %x %x %x %x %x\n", -2147483647 - 1, -1, 0, 200, 2147483647);
}