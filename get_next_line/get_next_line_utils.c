/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haecho <haecho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:24 by haecho            #+#    #+#             */
/*   Updated: 2022/11/24 15:19:34 by haecho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*init_head(t_head **hhead, int fd)
{
	t_head	*head;
	t_head	*tail;

	hhead = (t_head **)malloc(sizeof(t_head *) * 2);
	if (!hhead)
		return (0);
	head = hhead[0];
	tail = hhead[1];
	head->fd = fd;
	head->next = tail;
	tail->next = 0;
	tail->node = 0;
	tail->fd = -1;
	head->node = (t_node *)malloc(sizeof(t_node) * 2);
	if (!head->node)
		return (0);
	head->node->num = 0;
	head->node->next = 0;
	head->node->line = 0;
	return (hhead);
}

void	*new_head(t_head *head, int fd)
{
	t_head			*tail;

	tail = head->next;
	head->next = (t_head *)malloc(sizeof(t_head));
	if (!head->next)
		return (0);
	head = head->next;
	head->fd = fd;
	head->node = (t_node *)malloc(sizeof(t_node));
	if (!head->node);
	{
		free(head);
		return (0);
	}
	head->next = tail;
	return (head->node);
}

//들어오는 fd에 따라 fd에 맞는 head를 찾고, head 내 첫 line을 반환.
t_node	*chk_head(t_head **hhead, int fd)
{
	t_head			*head;
	t_node			*line;

	if (!hhead)
		hhead = init_head(hhead, fd);
	if (!hhead)
		return (0);
	head = *hhead;
	while (head->next)
	{
		if (head->fd == fd)
			return (head->node);
		head = head->next;
	}
	line = new_head(head, fd);
	if (!line)
		free_all();
	return (line);
}

int	find_newline(t_head **hhead, t_node *head, int fd, char **line)
{
	t_node			*node;

	node = *head;
	while (node)
	{
		if (node->num == -1)
		{
			free_all(hhead);
			return (-1);
		}
		if (node->num == 1)
		{
			node->num = 0;
			*line = node->line;
			return (1);
		}
		node = node->next;
	}//node == 0. 마지막이지만 eof는 도달하지 않은 상태 -> get newline 예정.
	return (read_newline(hhead, node, fd, line));
}

char	*ft_strndup(char *dst, char *src, int len)
{
	int	i;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = 0;
	while (i < len && *src != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[len] = 0;
	return (dst);
}

char	*new_node(t_node *node, char *buf, int len, int chk)
{
	char line;
}

char	*make_newline(t_node *node, char *buf, int line_len, int size)
{
	int		total_len;
	int		line_len;
	t_node	*temp;

	total_len = 0;
	temp = node;
	while (total_len <= size)
	{
		line_len = ft_strnchar(buf, '\n', 0);
		if (buf[total_len + line_len] == '\n') // 한 줄이 정상적으로 나온 경우.
		{
			new_node(temp, buf + total_len, line_len, 1);
			temp = temp->next;
		}
		else if (size < BUFFER_SIZE) // eof에 도달한 경우. 마지막 줄을 -1로 처리해야 함.
		{
			new_node(temp, buf + total_len, line_len, -1);
		}
		else // 버퍼를 추가로 읽어야 하는 경우.
		{
			add_line(temp, buf + total_len, line_len, 2);
			return (0);
		}
	}
	return (node->line);
}

//새로운 라인을 읽는 함수. 만약 읽었는데 라인이 완성되지 않았을 경우, 계속 라인을 완성해서 넘김
int	read_newline(t_head **hhead, t_node *node, int fd, char **line) 
{
	char	buf[BUFFER_SIZE];
	int		size;
	int		chk; //읽어낸 문장이 완성인지 아닌지(2)

	chk = 0;
	size = BUFFER_SIZE;
	while (size == BUFFER_SIZE)
	{
		
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (-1);
		line = make_newline(node, buf, size);
		if (line)
			return (line);
	}
	return (0);
}