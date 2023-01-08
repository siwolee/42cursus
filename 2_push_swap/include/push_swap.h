/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:37:00 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/09 00:46:24 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
// # include "../libft/libft.h"
# include <stdio.h>
// # include "get_next_line.h"

# define SA 1
# define SB 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RRA 7
# define RRB 8

# define SS 11
# define RR 12
# define RRR 13
# define PASS 140
# define END -1

# define ATOP 100
# define BTOP 101
# define ABOT 102
# define BBOT 103

# define C_PINK "\033[38;5;9m"
# define C_CYAN "\033[38;5;51m"
# define C_RED "\033[9m"
# define C_RS "\033[0m"

typedef struct s_node
{
	unsigned int	val;
	struct s_node	*next;
	struct s_node	*prev;
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
void	pri_callerr(char *name);
void	print_mb(int mb, int min);


//pretreat
int	ft_atoi(const char *str);
t_pre_val	*atoi_arr(int len, char **av, int *res);

void	pre_quick_sort(t_pre_val data[], int start, int end);
void	indexing(t_pre_val pre[], int res[], int len);
t_node	*newnode(int val);
void	init_stack(t_stack *s, int res[], int len);
void	init_index(t_pre_val *pre, int *res, int len);


//operater_
void	s_(t_stack *s, int ab);
void	sa(t_stack *s);
void	sb(t_stack *s);				
void	pa(t_stack *s);				
void	pb(t_stack *s);			
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rr_(t_stack *s, int ab);

// //operator_a,b
// int					sa(t_stack *s);//000
// int					sb(t_stack *s);//001
// int	ss(t_stack *s);//1000 = 8

// int					ra(t_stack *s);//100== 4
// int					rb(t_stack *s);//101== 5
// int	rr(t_stack *s);//1100= 12
// int					rra(t_stack *s);//110 == 6
// int					rrb(t_stack *s);//111 == 7
// int	rrr(t_stack *s);//1110 == 13


void				init_stack(t_stack *s, int res[], int len);

//mergesort
void	mergesort_atop(t_stack *s, unsigned int start, unsigned int end);
void	mergesort_btop(t_stack *s, unsigned int start, unsigned int end);
void	mergesort_abot(t_stack *s, unsigned int start, unsigned int end);
void	mergesort_bbot(t_stack *s, unsigned int start, unsigned int end);



void	execute(t_stack *s, char *act);

//shortsort
void	sort_short(t_stack *s, int size, char ab);
void	sort_two(t_stack *s, char ab);

void	sort_three(t_stack *s, char ab);
void	compare_three(t_stack *s, int a, int b, int c, char ab);
void	sort_three_123(t_stack *s, char ab);
void	sort_three_132(t_stack *s, char ab);
void	sort_three_213(t_stack *s, char ab);
void	sort_three_231(t_stack *s, char ab);
void	sort_three_312(t_stack *s, char ab);
void	sort_three_321(t_stack *s, char ab);

void	sort_four(t_stack *s, char ab);
void	sort_four_4xxx(t_stack *s, int val[], char ab);
void	sort_four_x4xx(t_stack *s, int val[], char ab);
void	sort_four_xx4x(t_stack *s, int val[], char ab);
void	sort_four_xxx4(t_stack *s, int val[], char ab);

void    print_queue(t_stack *s, char ab);
void    print_queue_ab(t_stack *s);

int		pri_all_sort(t_stack *s, int len);
int		pri_sort(t_stack *s, int len, char ab);

#endif