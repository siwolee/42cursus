/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:55:25 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/12 21:57:35 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if(n == 0)
		return (0);
	while (--n > 0 && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char *s1 = "atoms\0\0\0\0";
//  	char *s2 = "atoms\0abc";
//  	size_t size = 8;
//  	int i1 = memcmp(s1, s2, size);
//  	int i2 = ft_memcmp(s1, s2, size);

// 	printf("%d\n%d\n", i1, i2);
// 	if (i1 == i2)
// 		printf("$");
// }