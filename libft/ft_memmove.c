/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haecho <haecho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:59:35 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/12 13:22:16 by haecho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		chk;
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	chk = 1;
	i = -1;
	if (dst == src || len == 0)
		return (dst);
	if (dst > src && dst < src + len)
	{
		i = 0;
		while (++i <= len)
			d[len - i] = s[len - i];
	}
	else
	{
		while (++i < len)
			d[i] = s[i];
	}
	return (dst);
}
