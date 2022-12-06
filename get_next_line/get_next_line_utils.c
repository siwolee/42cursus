/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:24 by haecho            #+#    #+#             */
/*   Updated: 2022/12/05 12:12:17 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*init_node()
{
	t_node	*node;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->num = 2;
	node->next = 0;
	return (node);
}

void	*init_head(t_head **hhead, int fd)
{
	t_head	*head;

	hhead = (t_head **)malloc(sizeof(t_head *));
	if (!hhead)
		return (0);
	head = *hhead;
	head->fd = fd;
	head->next = 0;
	head->node = init_node();
	if (!head->node)
		return (0);
	return (hhead);
}

void	*new_head(t_head *head, int fd)
{
	t_head			*tail;

	tail = (t_head *)malloc(sizeof(t_head));
	tail = head->next;
	if (!tail)
		return (0);
	tail->fd = fd;
	tail->next = 0;
	tail->node = init_node();
	if (!tail->node);
		return (0);
	return (tail);
}

t_head	*get_head(t_head *head, int fd)
{
	while (head->fd != fd && head->next)
		head = head->next;
	if (head->fd == fd)
		return (head);
	else
		return (new_head(head, fd));
}

//들어오는 fd에 따라 fd에 맞는 head를 찾고, head 내 첫 line을 반환.
t_node	*chk_head(t_head **hhead, int fd)
{
	t_head			*head;
	t_node			*node;

	if (!hhead)
		hhead = init_head(hhead, fd);
	if (!hhead)
		return (0);
	head = get_head(*hhead, fd);
	return (head);
}

t_node	*last_node(t_node *node)
{
	while (node->next && node->num != 1)
		node = node->next;
	return (node);
}

t_node	*chk_line(t_head *head)
{
	t_node			*node;

	node = last_node(head->node);
	if (node->num == -1)
		return (0);
	if (node->num == 1)
		return (node);
	else
		return (read_line(node, head->fd));
	
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

t_node	*read_line(t_node *node, int fd)
{
	int		read_num;
	char	*buf;

	read_num == BUFFER_SIZE;
	while (read_num == BUFFER_SIZE)
	{
		read_num = read(fd, buf, BUFFR_SIZE);
		new_node(node, buf);
		if (chk_buf_n(buf, '\n'))
			return (node);
	}
	new_node
	return (node);
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