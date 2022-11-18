/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/18 13:26:00 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*new_word_to_c(char *str, char c)
// {
// 	int		len;
// 	char	*word;

// 	len = 0;
// 	while (str[len] != c && str[len])
// 		len++;
// 	word = ft_calloc(len + 1, sizeof(char));
// 	if (!word)
// 		return (0);
// 	ft_strlcpy(word, str, len + 1);
// 	return (word);
// }

// void	free_all(char **re)
// {
// 	int	i;

// 	i = 0;
// 	while (re[i] != 0)
// 	{
// 		free(re + i);
// 		i++;
// 	}
// 	free(re);
// }

// char	**ft_split_realloc(char **ptr, char *s, int cnt, int len)
// {
// 	char	**res;

// 	res = (char **)malloc(sizeof(char *) * cnt);
// 	if (!res)
// 		return (0);
// 	if (ptr != 0)
// 	{
// 		ft_memcpy((void *)res, (void *)ptr, (sizeof(char *) * (cnt - 1)));
// 		free(ptr);
// 		new_word_to_c
// 	}
// 	res[cnt] = 0;
// 	ptr = res;
// 	return (res);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		word_len;
// 	int		word_cnt;
// 	char	**res;

// 	i = 0;
// 	word_cnt = -1;
// 	res = ft_split_realloc(res, (char *)s + i, ++word_cnt + 2, word_len);
// 	if (!res)
// 		return (0);
// 	while (s[i] != '\0')
// 	{
// 		word_len = 0;
// 		while (word_len == 0)
// 		{
// 			word_len = is_c((char *)s + i, c);
// 			i++;
// 		}
// 		res = ft_split_realloc(res, (char *)s + i, ++word_cnt + 2, word_len);
// 		if (!res)
// 			break ;
// 		i += word_len;
// 	}
// 	if (s[i] != '\0')
// 		free_all(res);
// 	return (res);
// }



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
// 	system("leaks a.out");
// }
