# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
#                                                     +:+ +:+         +:+      #
#    By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 22:57:12 by siwolee           #+#    #+#              #
/*   Updated: 2022/11/07 23:16:30 by siwolee          ###   ########.fr       */
#                                                                              #
# **************************************************************************** #

#include <unistd.h>

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int ft_isalnum(int c)
{
	if (ft_isdigit(c))
		return (1);
	if (ft_isalpha(c))
		return (1);
	else
		return (0);
}

int ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

