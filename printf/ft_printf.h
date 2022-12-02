/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:58:14 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/01 23:16:59 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *buf, ...);

int		ft_isalpha(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

void	ft_putchar(char c);

char	*get_format(char **format, char *type);
void	print_char(char *format, char arg);
va_list	print_type(char *type, va_list arg_ptr);
void	print_escape(char c);
void	print_string(char *format, char *str);
void	print_format(char *format, char *str, int strlen);

void	print_pointer(char *format, void *ptr);


#endif