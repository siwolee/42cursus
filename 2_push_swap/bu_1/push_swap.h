/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:37:00 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/01 14:40:30 by siwolee          ###   ########.fr       */
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

struct	s_pre_val
{
	int	val;
	int	idx;
}typedef	t_pre_val;

//temporary
void	print_stacks(t_stack *a, t_stack *b);


//pretreat
void	pre_quick_sort(t_pre_val data[], int start, int end);
void	indexing(t_pre_val pre[], int res[], int len);
t_node	*newnode(int val);
void	init_stack(t_stack *a, int res[], int len);


//operator_a,b
int					sa(t_stack *a);//00
int					sb(t_stack *b);//01
// int	ss(t_stack *a, t_stack *b);//1000 = 8
int					pa(t_stack *a, t_stack *b);//10 = 2
int					pb(t_stack *a, t_stack *b);//11 = 3
int					ra(t_stack *a);//100== 4
int					rb(t_stack *b);//101== 5
// int	rr(t_stack *a, t_stack *b);//1100= 12
int					rra(t_stack *a);//110 == 6
int					rrb(t_stack *b);//111 == 7
// int	rrr(t_stack *a, t_stack *b);//1110 == 13

void				init_stack(t_stack *a, int res[], int len);
void				print_stack(t_stack *a);

//mergesort
void				mergesort_atop(t_stack *a, t_stack *b, unsigned int start, unsigned int end);


int					execute(t_stack *a, t_stack *b, ...);

#endif