/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:24 by haecho            #+#    #+#             */
/*   Updated: 2022/12/06 19:27:20 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


//들어오는 fd에 따라 fd에 맞는 head를 찾고, head 내 첫 line을 반환.
t_head	*chk_head(t_head **hhead, int fd)
{
	t_head			*head;

	head = get_head(*hhead, fd);
	if (!hhead)
		return (0);
	return (head);
}

t_head	**init_head(int fd)
{
	t_head	**hhead;
	t_head	*head;

	hhead = (t_head **)malloc(sizeof(t_head *));
	if (!hhead)
		return (0);
	head = (t_head *)malloc(sizeof(t_head));
	if (!head)
		return (0);
	*hhead = head;
	head->fd = fd;
	head->next = 0;
	head->node = init_node();
	if (!head->node)
		return (0);
	return (hhead);
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
	if (!tail->node)
		return (0);
	return (tail);
}

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

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s && s[size])
		size++;
	return (size);
}

t_node	*last_unout_node(t_head *head)
{
	t_node	*node;
	t_node	*next;

	node = head->node;
	while (node->next && node->num != 1)
	{
		next = node->next;
		if (node->num == 0)
		{
			free(node->line);
			free(node);
		}
		node = next;
	}
	head->node = node;
	return (node);
}

t_node	*last_node(t_node *node)
{
	while (node->next)
		node = node->next;
	return (node);
}

t_node	*chk_line(t_head *head)
{
	t_node			*node;

	node = last_unout_node(head);
	if (node->num == -1 || node->num == 1)
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
	t_node	*tail;

	read_num = BUFFER_SIZE;
	buf = (char *)ft_calloc(BUFFER_SIZE);
	if (!buf)
		return (0);
	while (read_num == BUFFER_SIZE)
	{
		read_num = read(fd, buf, BUFFER_SIZE);
		tail = last_node(node);
		if (new_node(tail, buf))
			return (0);
		if (chk_buf_n(node->line, '\n'))
			return (node);
	}
	close(fd);
	return (node);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	idx;

	if (!src)
		return (0);
	d_len = 0;
	s_len = 0;
	idx = -1;
	while (dst[d_len])
		d_len++;
	while (src[s_len])
		s_len++;
	if (d_len >= dstsize)
		return (s_len + dstsize);
	if (dstsize == 0)
		return (s_len);
	while (src[++idx] && idx + d_len < dstsize - 1)
		dst[d_len + idx] = src[idx];
	dst[d_len + idx] = 0;
	return (d_len + s_len);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i])
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char *ft_calloc(size_t bufsize)
{
	char	*str;

	str = (char *)malloc(bufsize);
	while (str[--bufsize])
		str[bufsize] = 0;
	return (str);
}

void	realloc_line(t_node *node, char *buf, size_t bufsize)
{
	char	*newline;

	newline = ft_calloc(bufsize);
	if (!newline)
	{
		node->line = 0;
		return ;
	}
	ft_strlcat(newline, node->line, ft_strlen(node->line));
	ft_strlcat(newline, buf, bufsize);
	if (node->line)
		free(node->line);
	node->line = newline;
}

int	chk_buf_length(char *buf, char n)
{
	int i;

	i = 0;
	while (buf[i] && buf[i] != n)
		i++;
	return (i);
}

int	chk_buf_n(char *buf, char n)
{
	int i;

	i = 0;
	while (buf[i] && buf[i] != n)
		i++;
	if (buf[i] == n)
		return (1);
	else
		return (0);
}

int	new_node(t_node *node, char *buf)
{
	size_t	bufsize;
	t_node	*new;

	bufsize = ft_strlen(buf);
	new = node;
	while (bufsize)
	{
		bufsize = chk_buf_length(buf, '\n');
		if (node->num == 2)
			realloc_line(node, buf, ft_strlen(node->line) + bufsize);
		else
		{
			node->next = (t_node *)malloc(sizeof(t_node));
			node->
			ft_strndup(node->line, buf, bufsize);
		}
		if (!node->line)
			return (0);
	}
	return (1);
}

void	free_head(t_head **hhead, t_head *head)
{
	t_head	*before;
	t_node	*node;
	t_node	*n_node;

	before = *hhead;
	while (before != head)
		before = before->next;
	before->next = head->next;
	node = head->node;
	while (node)
	{
		n_node = node->next;
		free(node->line);
		free(node);
		node = n_node;
	}
	free(head);
}

void	free_all(t_head **hhead)
{
	t_head	*head;
	t_head	*n_head;
	t_node	*node;
	t_node	*n_node;

	head = *hhead;
	while (head)
	{
		n_head = head->next;
		node = head->node;
		while (node)
		{
			n_node = node->next;
			free(node->line);
			free(node);
			node = n_node;
		}
		free(head);
		head = n_head;
	}
	free(hhead);
}

// char	*make_newline(t_node *node, char *buf, int line_len, int size)
// {
// 	int		total_len;
// 	int		line_len;
// 	t_node	*temp;

// 	total_len = 0;
// 	temp = node;
// 	while (total_len <= size)
// 	{
// 		line_len = ft_strnchar(buf, '\n', 0);
// 		if (buf[total_len + line_len] == '\n') // 한 줄이 정상적으로 나온 경우.
// 		{
// 			new_node(temp, buf + total_len, line_len, 1);
// 			temp = temp->next;
// 		}
// 		else if (size < BUFFER_SIZE) // eof에 도달한 경우. 마지막 줄을 -1로 처리해야 함.
// 		{
// 			new_node(temp, buf + total_len, line_len, -1);
// 		}
// 		else // 버퍼를 추가로 읽어야 하는 경우.
// 		{
// 			add_line(temp, buf + total_len, line_len, 2);
// 			return (0);
// 		}
// 	}
// 	return (node->line);
// }

// //새로운 라인을 읽는 함수. 만약 읽었는데 라인이 완성되지 않았을 경우, 계속 라인을 완성해서 넘김
// int	read_newline(t_head **hhead, t_node *node, int fd, char **line) 
// {
// 	char	buf[BUFFER_SIZE];
// 	int		size;
// 	int		chk; //읽어낸 문장이 완성인지 아닌지(2)

// 	chk = 0;
// 	size = BUFFER_SIZE;
// 	while (size == BUFFER_SIZE)
// 	{
		
// 		size = read(fd, buf, BUFFER_SIZE);
// 		if (size < 0)
// 			return (-1);
// 		line = make_newline(node, buf, size);
// 		if (line)
// 			return (line);
// 	}
// 	return (0);
// }