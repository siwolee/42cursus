/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:02:09 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/08 21:41:14 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _LIBFT_H_
# ifndef _LIBFT_H_

/* isalpha -- make static islower and upper*/
int				ft_isalpha(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/* isdigit.c */
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);

/* ft_strlen.c */
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			strncmp(char *s1, char *s2, unsigned int n);
unsigned long	strlen(const char *s);

/* ft_mem.c */
void			*memset(void *b, int c, unsigned long len);


# endif
