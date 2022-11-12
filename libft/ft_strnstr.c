/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/11 19:44:34 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	char	*hay;

	hay = (char *)haystack;
	if (*needle == 0)
		return (hay);
	while (len-- && *hay != '\0')
	{
		if (*hay == needle[0])
		{
			n_len = 1;
			while (needle[n_len] != '\0' && needle[n_len] == hay[n_len])
				n_len ++;
			if (needle[n_len] == '\0')
				return (hay);
		}
		hay++;
	}
	return (0);
}
