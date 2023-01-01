/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:37:00 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/01 22:14:34 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	unsigned int	val;
	struct s_node	*next;
	struct s_node	*before;
}					t_node;

typedef struct s_stack
{
	t_node			*atop;
	t_node			*abot;
	t_node			*btop;
	t_node			*bbot;
	int				asize;
	int				bsize;
}					t_stack;

struct	s_pre_val
{
	int	val;
	int	idx;
}typedef	t_pre_val;

//temporary
void	print_stacks(t_stack *s);
void	print_stack(t_stack *s, int ab);


//pretreat
void	pre_quick_sort(t_pre_val data[], int start, int end);
void	indexing(t_pre_val pre[], int res[], int len);
t_node	*newnode(int val);
void	init_stack(t_stack *s, int res[], int len);


//operater_
void	s_(t_stack *s, int ab);
void	p_(t_stack *s, int ab);
void	r_(t_stack *s, int ab);
void	rr_(t_stack *s, int ab);

//operator_a,b
int					sa(t_stack *s);//000
int					sb(t_stack *s);//001
// int	ss(t_stack *s);//1000 = 8
int					pa(t_stack *s);//010 = 2
int					pb(t_stack *s);//011 = 3
int					ra(t_stack *s);//100== 4
int					rb(t_stack *s);//101== 5
// int	rr(t_stack *s);//1100= 12
int					rra(t_stack *s);//110 == 6
int					rrb(t_stack *s);//111 == 7
// int	rrr(t_stack *s);//1110 == 13

void				init_stack(t_stack *s, int res[], int len);

//mergesort
void				mergesort_atop(t_stack *s, unsigned int start, unsigned int end);


int					execute(t_stack *s, ...);

#endif