/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:37:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/27 20:55:44 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	unsigned int	val;
	struct s_node	*next;
	struct s_node	*before;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bot;
	int				size;
}					t_stack;

int					sa(t_stack *a);
int					sb(t_stack *a);
// int	ss(t_stack *a, t_stack *b);
int					pa(t_stack *a, t_stack *b);
int					pb(t_stack *a, t_stack *b);
int					ra(t_stack *a);
int					rb(t_stack *a);
// int	rr(t_stack *a, t_stack *b);
int					rra(t_stack *a);
int					rrb(t_stack *a);
// int	rrr(t_stack *a, t_stack *b);

int					init_stack(int *temp, int ac, t_stack *a);
void				print_stack(t_stack *a);

#endif