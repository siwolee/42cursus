/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:37:00 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/17 21:13:06 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./ansi_color.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SA '1'
# define SB '2'
# define PA '3'
# define PB '4'
# define RA '5'
# define RB '6'
# define RRA '7'
# define RRB '8'

# define SS 91
# define RR 92
# define RRR 93
# define PASS 94

# define ATOP 101
# define BTOP 102
# define ABOT 103
# define BBOT 104

# define ACTMAX 200000

typedef struct s_act
{
	char			arr[ACTMAX];
	struct s_act	*next;
}					t_act;

typedef struct s_node
{
	unsigned int	val;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_act			*act;
	t_node			*atop;
	t_node			*abot;
	t_node			*btop;
	t_node			*bbot;
	int				asize;
	int				bsize;
}					t_stack;

typedef struct s_pre_val
{
	int				val;
	int				idx;
}					t_pre_val;

typedef struct s_pivot
{
	unsigned int	len;
	unsigned int	pivot1;
	unsigned int	pivot2;
}					t_pivot;

//temporary
void				call_err(char *name);
void				print_mb(int mb, int min);
void				print_queue(t_stack *s, char ab);
void				print_queue_ab(t_stack *s);

//pretreat
int					ft_atoi(const char *str);
int					pretreat(t_stack *s, char **av, int len);
int					indexing(t_pre_val *pre, int i, int val);

//aftertreat
void				print_exec(char c);

//stack
t_node				*newnode(int val);
int					init_stack(t_stack *s, t_pre_val *pre, int len);
void				free_stack(t_stack *s);

//operater_
void				sa(t_stack *s);
void				sb(t_stack *s);
void				pa(t_stack *s);
void				pb(t_stack *s);
void				ra(t_stack *s);
void				rb(t_stack *s);
void				rra(t_stack *s);
void				rrb(t_stack *s);
void				ss(t_stack *s);
void				rr(t_stack *s);
void				rrr(t_stack *s);

//mergesort
t_node				*get_top(t_stack *s, char *ab, int len);
void				sort_merge(t_stack *s, unsigned int start, unsigned int end,
						char ab);
t_pivot				*new_pivot(unsigned int start, unsigned int end);
char				get_mostbig_ab(char ab);
char				get_big_ab(char ab);
char				get_small_ab(char ab);
void				sort_merge_big(t_stack *s, char ab);
void				sort_merge_small(t_stack *s, char ab);
void				sort_merge_mostbig(t_stack *s, char ab);

//execute
void				ft_bzero(void *s, size_t n);
t_act				*init_act(void);
t_act				*add_act(t_act *act);
void				add_act_len(t_act *act, char newact);
void				execute(t_stack *s, char *newact);
void				print_final(t_stack *s);
void				optimization(t_act *act);
void				chk_double(char *a, char *b);

//shortsort
void				sort_short(t_stack *s, t_pivot *p, char ab);
void				sort_two(t_stack *s, char ab);

void				sort_two(t_stack *s, char ab);
void				sort_two_atop(t_stack *s, unsigned int a, unsigned int b);
void				sort_two_btop(t_stack *s, unsigned int a, unsigned int b);
void				sort_two_abot(t_stack *s, unsigned int a, unsigned int b);
void				sort_two_bbot(t_stack *s, unsigned int a, unsigned int b);

unsigned int		get_max_idx(t_stack *s, char ab);

void				sort_four(t_stack *s, char ab);

void				sort_four_eqaulsize_a(t_stack *s, unsigned int max_idx);
void				sort_four_eqaulsize_b(t_stack *s, unsigned int max_idx);
void				sort_four_atop(t_stack *s, unsigned int max_idx);
void				sort_four_btop(t_stack *s, unsigned int max_idx);
void				sort_four_abot(t_stack *s, unsigned int max_idx);
void				sort_four_bbot(t_stack *s, unsigned int max_idx);

void				sort_three(t_stack *s, char ab);
void				sort_three_ab(t_stack *s, t_node *a, char ab);
void				sort_three_atop(t_stack *s, unsigned int a);
void				sort_three_btop(t_stack *s, unsigned int a);

int					chk_sorted_final(t_stack *s, int len);
int					chk_sorted(t_stack *s, int len);

#endif