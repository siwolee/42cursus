/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haecho <haecho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/19 12:07:08 by haecho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*to_c(char *str, char c)
{
	int		len;
	char	*word;

	len = 0;
	
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

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_len;
	int		word_cnt;
	char	**res;

	word_cnt = get_word_cnt(s, c);
	if (!(res = malloc(sizeof(char *) * (word_cnt + 1))))
		return (0);
	i = 0;
	while (i != word_cnt)
	{
		new_word(res[i], c);
		if (!res[i])
		{
			free_all(res);
			return (0);
		}
		i++;
	}
	return (res);
}
