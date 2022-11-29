/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:58:14 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/29 21:56:06 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_isalpha(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

void	putchar(char c);

char	*get_format(char **format, char *type);
void	print_char(char *format, char *type, char arg);
void	print_type(char *type, va_list arg_list);
void	print_escape(char *c);

#endif