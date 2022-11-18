/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haecho <haecho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/15 00:18:16 by haecho           ###   ########.fr       */
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

int	get_m_size(char *s, char c)
{
	int	cnt;
	int	word_len;

	cnt = 0;
	while (*s)
	{
		word_len = is_c(s, c);
		if (word_len > 0)
		{
			cnt++;
			s += word_len;
		}
		s++;
	}
	return (cnt);
}

void	free_all(char **re, int word_cnt)
{
	while (word_cnt >= 0)
	{
		free(re[word_cnt]);
		word_cnt--;
	}
	free(re);
}

int	split_words(char *s, char c, char **re)
{
	int	idx;
	int	word_cnt;
	int	word_len;

	idx = 0;
	word_cnt = 0;
	word_len = 0;
	while (s[idx])
	{
		word_len = is_c(s + idx, c);
		if (word_len)
		{
			re[word_cnt] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (!re[word_cnt])
				return (word_cnt);
			ft_strlcpy(re[word_cnt], s + idx, word_len + 1);
			idx += word_len + 1;
			word_cnt++;
		}
		else
			idx++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	int		word_cnt;
	int		error;

	word_cnt = get_m_size((char *)s, c);
	re = malloc(sizeof(char *) * (word_cnt + 1));
	if (!re)
		return (0);
	error = split_words((char *)s, c, re);
	if (error > 0)
	{
		free_all(re, error);
		return (0);
	}
	re[word_cnt] = 0;
	return (re);
}

#include <stdio.h>
int main()
{
	char **p;
	p = ft_split("hello", ' ');
	free(p[0]);
	free(p[1]);
	free(p);
	system("leaks a.out");
}
