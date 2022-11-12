/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/12 20:29:01 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	if (*ptr == '\0' && c == '\0')
		return (ptr);
	while (*ptr != '\0')
		ptr++;
	while (ptr != s || c == '\0')
	{
		ptr--;
		if (*ptr == (char)c)
			return (ptr);
	}
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	char	*str;
// 	char	str2[] = "";

// 	str = ft_strrchr(str2, '\0');
// 	if (!(str))
//         printf("%s",NULL);
//     else
//     {
//         printf("%s", str);
//         if (str != str2 + 7)
//             printf("\nReturn value is false");
//     }
// }