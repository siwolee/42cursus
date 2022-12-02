/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:58:14 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/02 21:18:21 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *buf, ...);

int		ft_isalpha(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

void	ft_putchar(char c);

char	*get_format(char **format, char *type);
int		print_char(char *format, char arg);
int		print_type(char *type, va_list arg_ptr);
int		print_escape(char c);
int		print_string(char *format, char *str);
int		print_format(char *format, char *str, int strlen);

int		print_pointer(char *format, void *ptr);

int		get_itoa(int sign, char buf[], long long arg);
int		print_integer(char *format, int arg);
int		print_unsigened_int(char *format, unsigned int);
int		print_num_in_hex_low(char *format, int arg);
int		print_num_in_hex_up(char *format, int arg);


#endif