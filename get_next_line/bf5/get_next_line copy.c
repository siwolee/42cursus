/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:53:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/08 16:25:28 by siwolee          ###   ########.fr       */
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
		buf = ft_calloc(BUFFER_SIZE);
	if (!buf)
		return (0);
	line = read_line(&buf, fd, line, &chk);
	return (line);
}
