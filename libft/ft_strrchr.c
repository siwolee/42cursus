/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haecho <haecho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/12 13:29:44 by haecho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	if (*s == '\0' && (char)c == '\0')
		return (ptr);
	while (*ptr != '\0')
		ptr++;
	while (ptr != s)
	{
		ptr--;
		if (*ptr == (char)c)
			return (ptr);
	}
	return (0);
}

#include <stdio.h>
int main()
{
	char dst[] = "";

	if (!(ft_strrchr(dst, '\0')))
        printf("NULL");
    else
    {
        printf("%s",dst);
    }
}
