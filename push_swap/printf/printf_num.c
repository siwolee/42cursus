/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:37:09 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/14 18:59:12 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(char *format, int arg)
{
	char		*ten;
	long long	llarg;

	ten = "0123456789";
	format = NULL;
	llarg = (long long)arg;
	return (requr_integer(llarg, ten));
}

int	print_unsigened_int(char *format, unsigned int arg)
{
	char		*ten;
	long long	llarg;

	ten = "0123456789";
	format = NULL;
	llarg = (long long)arg;
	return (requr_integer(llarg, ten));
}

int	requr_integer(long long ptr, char *ten)
{
	int	now;
	int	requr;

	requr = 0;
	if (ptr < 0)
	{
		now = write(1, "-", 1);
		if (now == -1)
			return (-1);
		requr = requr_integer(ptr * (-1), ten);
		if (requr < 0)
			return (-1);
		return (now + requr);
	}
	if (ptr >= 10)
		requr = requr_integer(ptr / 10, ten);
	if (requr < 0)
		return (-1);
	now = write(1, &(ten[ptr % 10]), 1);
	if (now == -1)
		return (-1);
	return (now + requr);
}
