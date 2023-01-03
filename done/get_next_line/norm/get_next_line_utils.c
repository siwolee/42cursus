/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/21 15:00:40 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	n;
	size_t	i;

	n = count * size;
	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

int	chk_n_idx(char buf[], char n)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf[i] && buf[i] != n)
		i++;
	if (buf[i] == n)
		return (i);
	return (-1);
}
