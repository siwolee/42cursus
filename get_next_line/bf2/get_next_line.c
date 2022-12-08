/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/07 23:53:27 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			chk;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = 0;
	chk = 0;
	if (!buf)
		buf = ft_calloc(1024);
	line = read_line(buf, fd, line, &chk);
	buf = seperate_buf(buf, &chk);
	return (line);
}