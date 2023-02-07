/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:12:49 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/20 16:04:12 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num_in_hex(char *format, int arg, char x)
{
	char			*hex_low;
	char			*hex_up;
	int				size;
	unsigned int	llarg;

	hex_low = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	format = NULL;
	llarg = (unsigned int)arg;
	if (x == 'X')
		size = requr_hex(llarg, hex_up);
	else
		size = requr_hex(llarg, hex_low);
	return (size);
}

int	requr_hex(unsigned int ptr, char *hex)
{
	int	now;
	int	requr;

	requr = 0;
	if (ptr >= 16)
		requr = requr_hex(ptr / 16, hex);
	if (requr < 0)
		return (-1);
	now = write(1, &(hex[ptr % 16]), 1);
	if (now == -1)
		return (-1);
	return (now + requr);
}
