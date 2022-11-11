/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:17:51 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/08 20:31:38 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while(*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return (s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	while(*s)
		s++;
	if (*s == '\0' && c == '\0')
		return (s);
	while(*s)
	{
		if (*s == c)
			return (s);
		s--;
	}
	return (NULL);
}

unsigned long	strlen(const char *s)
{
	unsigned long	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 0 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

