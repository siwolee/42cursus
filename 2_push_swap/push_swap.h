/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:37:00 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/23 22:54:16 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
// # include "libftprintf.a"
# include <stdio.h>
# define NAME_(x) #x

typedef struct s_node
{
	int	val;
	struct s_node	*up;
	struct s_node	*down;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}	t_stack;

int	s(t_stack *a);
int	p(t_stack *a, t_stack *b);
int r(t_stack *a);
int rr(t_stack *a);

int init_stack(int *temp, int ac, t_stack *a);
void print_stack(t_stack *a);

#endif