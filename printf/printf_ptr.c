/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:40:32 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/14 17:11:27 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(char *format, void *ptr)
{
	char	*hex;
	size_t	ptr2;
	int		size;

	if (format != NULL)
		return (0);
	hex = "0123456789abcdef";
	ptr2 = (size_t)ptr;
	if (ptr2 == 0)
		return (write(1, "0x0", 3));
	if (write(1, "0x", 2) < 0)
		return (-1);
	size = requr_pointer(ptr2, hex);
	if (size < 0)
		return (-1);
	size += 2;
	return (size);
}

int	requr_pointer(size_t ptr, char *hex)
{
	int	now;
	int	requr;

	requr = 0;
	if (ptr >= 16)
		requr = requr_pointer(ptr / 16, hex);
	if (requr < 0)
		return (-1);
	now = write(1, &(hex[ptr % 16]), 1);
	if (now == -1)
		return (-1);
	return (now + requr);
}
