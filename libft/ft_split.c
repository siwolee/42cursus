/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/13 18:06:04 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

int	get_malloc_size(char *str, char c)
{
	int	i;
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str== c)
		{
			cnt++;
			str += i;
		}
		else
			str++;
	}
	return (cnt);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = -1;
	while (src[++i] && i < n)
		dest[i] = src[i];
	dest[i] = 0;
}

int	new_split(char **split, int cnt, char *str, int len)
{
	split[cnt] = malloc(sizeof(char) * (len + 1));
	ft_strncpy(split[cnt], str, len);
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		word_cnt;
	int		word_len;
	int		len;
	char	**split;

	if (!*s)
		return (0);
	word_len = get_malloc_size(s, c);
	split = malloc(sizeof(char *) * (word_len + 1));
	if (!split)
		return (0);
	word_cnt = -1;
	split[word_len] = 0;
	len = 0;
	while (word_cnt < word_len && *s)
	{
		len = is_c(s, c);
		if (len && ++word_cnt >= 0)
			s += new_split(split, word_cnt, s, len);
		else
			s++;
	}
	return (split);
}
