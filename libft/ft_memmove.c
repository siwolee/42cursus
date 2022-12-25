/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:59:35 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/24 18:59:22 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		d += len - 1;
		s += len - 1;
		while (i < len)
		{
			*d-- = *s--;
			i++;
		}
		return (dst);
	}
	while (i < len)
	{
		*d++ = *s++;
		i++;
	}
	return (dst);
}
