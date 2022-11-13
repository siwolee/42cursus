/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haecho <haecho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/13 15:15:41 by haecho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (len == 0)
		return (0);
	ptr = (char *)s;
	i = -1;
	while (++i <= len && ptr[i] != '\0')
		i++;
	len = i;
	ptr = (char *)malloc(sizeof(char) * i + 1);
	if (!ptr)
		return (0);
	i = -1;
	while (s[start + ++i] != '\0' && i < len)
		ptr[i] = s[start + i];
	return (ptr);
}

int main()
{
	char	str[] = "abcde";
	char	emp[] = "";
	char	*re;

	re = ft_substr(str, 0, 0);
	free(re);
	re = ft_substr(emp, 0, 0);
	free(re);
}
