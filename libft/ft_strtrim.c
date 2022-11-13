/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/13 17:43:11 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	chk_set(char *s, char const *set)
{
	int	i;

	i = 0;
	while (set[i] && set[i] != *s)
		i++;
	if (set[i] == *s)
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	len;

	if (!*s1)
	{
		ptr = ft_calloc(1,1);
		if (!ptr)
			return (0);
		return (ptr);
	}
	start = 0;
	len = ft_strlen(s1);
	while (s1[start] && chk_set((char *)s1 + start, set))
		start++;
	while (chk_set((char *)s1 + len, set))
		len--;
	len++;
	len -= start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1 + start, len + 1);
	return (ptr);
}

// int main()
// {
// 	char s[] = "    ";
// 	ft_strtrim(s, " ");
// }