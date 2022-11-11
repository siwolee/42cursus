/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:59:35 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/09 23:55:58 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned long len)
{
	unsigned char uc;
	void	*result;

	uc = (unsigned char)c;
	result = b;
	while (len)
	{
		*(unsigned char *)b = uc;
		b++;
		len--;
	}
	return (result);
}

void	*ft_memmove(void *dst, const void *src, unsigned long len)
{
	void	*re;

	re = dst;
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len > 0)
		{
			src--;
			dst--;
			*(char *)dst = *(char *)src;
			len--;
		}
	}
	else
	{
		while (len)
		{
			*(char *)dst = *(char *)src;
			src++;
			dst++;
			len--;
		}
	}
	return (re);
}


