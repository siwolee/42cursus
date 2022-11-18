/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_realloc_bu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haecho <haecho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/16 10:43:47 by haecho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

void	free_all(char **re)
{
	int	i;

	i = 0;
	while (re[i] != 0)
	{
		free(re + i);
		i++;
	}
	free(re);
}

char	**ft_split_realloc(char **ptr, size_t cnt, size_t size)
{
	char	**res;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	res = (char **)malloc(cnt * size);
	if (!res)
		return (0);
	if (ptr != 0)
		ft_memcpy((void *)res, (void *)ptr, size * (cnt - 1));
	free(ptr);
	res[cnt] = (char *)ft_calloc(word_len + 1, sizeof(char));

	res[cnt] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_len;
	int		word_cnt;
	char	**res;

	i = 0;
	word_cnt = -1;
	res = 0;
	while (s[i] != '\0')
	{
		word_len = 0;
		while (word_len == 0)
			word_len = is_c((char *)s + i++, c);
		res = ft_split_realloc(res, ++word_cnt + 2, sizeof(char *));
		if (!res)
			break ;
		if (!res[word_cnt])
			break ;
		ft_strlcpy(res[word_cnt], s + --i, word_len + 1);
		i += word_len;
	}
	if (s[i] != '\0')
		free_all(res);
	return (res);
}



// #include <stdio.h>
// int main()
// {
// 	char **p;
// 	int	i;

// 	i =-1;
// 	p = ft_split("dsdayud7sgdasgf", 'd');
// 	while (p[++i])
// 		printf("%d : %s\n", i, p[i]);
// 	//free_all(p);
// 	//system("leaks a.out");
// }
