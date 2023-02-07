/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:58:14 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/20 15:55:55 by siwolee          ###   ########.fr       */
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
void	*ft_calloc(size_t count, size_t size);

int		ft_putchar(char c);

int		print_type(char *type, va_list *arg_ptr);
int		print_format(char *format, char *str, int strlen);
char	*get_format(char **format, char *type);
int		print_escape(char c);

int		print_char(char *format, char arg);
int		print_string(char *format, char *str);

int		print_pointer(char *format, void *ptr);
int		requr_pointer(size_t ptr, char *hex);

int		print_integer(char *format, int arg);
int		requr_integer(long long ptr, char *ten);
int		print_unsigened_int(char *format, unsigned int arg);

int		print_num_in_hex(char *format, int arg, char x);
int		requr_hex(unsigned int ptr, char *hex);

char	*return_format_str(char *format, char *str, int strlen);

#endif