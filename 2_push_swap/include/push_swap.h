/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:37:00 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/12 19:06:24 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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

# define ACTMAX 1000

# define C_PINK "\033[38;5;9m"
# define C_CYAN "\033[38;5;51m"
# define C_RED "\033[9m"
# define C_RS "\033[0m"

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

typedef struct	s_pre_val
{
	int	val;
	int	idx;
}				t_pre_val;

//temporary
void	print_stacks(t_stack *s);
void	print_stack(t_stack *s, int ab);
void	pri_callerr(char *name);
void	print_mb(int mb, int min);

//pretreat
int	ft_atoi(const char *str);
int pretreat(t_stack *s, char **av, int len);
int	indexing(t_pre_val *pre, int i, int val);

//stack
t_node	*newnode(int val);
int	init_stack(t_stack *s, t_pre_val *pre, int len);
void	free_stack(t_stack *s);

//operater_
void	sa(t_stack *s);
void	sb(t_stack *s);				
void	pa(t_stack *s);				
void	pb(t_stack *s);			
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	ss(t_stack *s);
void	rr(t_stack *s);
void	rrr(t_stack *s);

//mergesort
void	mergesort_atop(t_stack *s, unsigned int start, unsigned int end);
void	mergesort_btop(t_stack *s, unsigned int start, unsigned int end);
void	mergesort_abot(t_stack *s, unsigned int start, unsigned int end);
void	mergesort_bbot(t_stack *s, unsigned int start, unsigned int end);

void	merge_sort(t_stack *s, char ab, int len, unsigned int pivot);
int	sort_big(t_stack *s, char ab);
int	sort_small(t_stack *s, char ab);
t_node	*get_top(t_stack *s, char ab);
char	get_big_ab(char ab);
char	get_small_ab(char ab);

//execute
void	ft_bzero(void *s, size_t n);
t_act	*init_act();
t_act	*add_act(t_act *act);
void	add_act_len(t_act *act,char newact);
void	execute(t_stack *s, char *newact);
void	print_final(t_stack *s);
void	optimization(t_act *act);

//shortsort
void	sort_short(t_stack *s, int size, char ab);
void	sort_two(t_stack *s, char ab);

void	sort_two(t_stack *s, char ab);
void	sort_two_atop(t_stack *s, unsigned int a, unsigned int b);
void	sort_two_btop(t_stack *s, unsigned int a, unsigned int b);
void	sort_two_abot(t_stack *s, unsigned int a, unsigned int b);
void	sort_two_bbot(t_stack *s, unsigned int a, unsigned int b);

void	get_max_idx(t_stack *s, unsigned int val[4], char ab);
void	sort_four(t_stack *s, char ab);
void	sort_four_atop(t_stack *s, unsigned int val[]);
void	sort_four_btop(t_stack *s, unsigned int val[]);
void	sort_four_abot(t_stack *s, unsigned int val[]);
void	sort_four_bbot(t_stack *s, unsigned int val[]);

void	sort_three(t_stack *s, char ab);
void	sort_three_ab(t_stack *s, int a, int b, int c, char ab);
void	sort_three_atop(t_stack *s, unsigned int a, unsigned int b, unsigned int c);
void	sort_three_btop(t_stack *s, unsigned int a, unsigned int b, unsigned int c);

// void	sort_three(t_stack *s, char ab);
// void	compare_three(t_stack *s, int a, int b, int c, char ab);
// void	sort_three_123(t_stack *s, char ab);
// void	sort_three_132(t_stack *s, char ab);
// void	sort_three_213(t_stack *s, char ab);
// void	sort_three_231(t_stack *s, char ab);
// void	sort_three_312(t_stack *s, char ab);
// void	sort_three_321(t_stack *s, char ab);

// void	sort_four(t_stack *s, char ab);
// void	sort_four_4xxx(t_stack *s, int val[], char ab);
// void	sort_four_x4xx(t_stack *s, int val[], char ab);
// void	sort_four_xx4x(t_stack *s, int val[], char ab);
// void	sort_four_xxx4(t_stack *s, int val[], char ab);

void	print_queue(t_stack *s, char ab);
void	print_queue_ab(t_stack *s);

int		pri_all_sort(t_stack *s, int len);
int		pri_sort(t_stack *s, int len, char ab);

void	chk_double(char *a, char *b);

#endif