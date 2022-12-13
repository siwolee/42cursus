/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:58:34 by haecho            #+#    #+#             */
/*   Updated: 2022/12/10 00:13:35 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifdef BUFFER_SIZE

# else
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				fd;
	char			*buf;
	struct s_list	*next;
}			t_list;

char		*ft_calloc(size_t count, size_t size);
// char		*ft_substr(char const *s, unsigned int start, size_t len);
// size_t		ft_strlen(const char *s);
size_t		ft_strncat(char *dst, const char *src, size_t srcsize);

char		*get_next_line(int fd);

t_list		*init_list(int fd);
int			chk_n_idx(char *buf);
char		*read_line(t_list **lst);
char		*new_line(t_list *lst, char *line);
char		*split_buf(t_list *lst, size_t b_idx);

t_list		*chk_list(t_list **lst, int fd);
t_list		*remove_list(t_list **lst, t_list *fd_lst);

#endif