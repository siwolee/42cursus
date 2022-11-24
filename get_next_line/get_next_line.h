/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haecho <haecho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:34 by haecho            #+#    #+#             */
/*   Updated: 2022/11/23 12:47:25 by haecho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 42

typedef struct	s_node
{
	char			*line;
	int			num; // 마지막 eof 감지시 -1, 내보냄 0, 안내보냄 1. 미완 2. 첫 라인 초기화를 뭘로 해야 할까?
	struct s_node	*next;
}	t_node;

typedef struct	s_head
{
	ssize_t			fd;
	struct s_head	*next;
	struct s_node	*node;
}	t_head;

char	*get_next_line(int fd);

#endif