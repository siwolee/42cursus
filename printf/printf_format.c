/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:07:24 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/08 14:45:15 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_format(char **format, char *type)
{
	int	i;

	i = 0;
	if (!type)
		return (0);
	while (ft_isalpha(type[i]) != 1)
		i++;
	if (i != 0)
	{
		*format = calloc(i, 1);
		if (!*format)
			return (0);
		ft_strlcpy(*format, type, i);
	}
	else
		*format = 0;
	return (type + i);
}

int	print_format(char *format, char *str, int strlen)
{
	char	*format_str;
	int		format_len;

	format_str = return_format_str(format, str, strlen);
	if (!format_str)
	{
		free(format);
		return (-1);
	}
	format_len = ft_strlen(format_str);
	write(1, format_str, format_len);
	free(format_str);
	free(format);
	return (format_len);
}

char	*return_format_str(char *format, char *str, int strlen)
{
	if (*format == '#')
		return (1);
}
