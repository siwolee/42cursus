


# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"

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
	char			**split;
}					t_stack;

typedef struct s_pre_val
{
	int				val;
	int				idx;
}					t_pre_val;


int		ft_atoi(const char *str);
void	atoi_arr(int len, char **av, int *res);
t_node	*newnode(int val);
void	init_stack(t_stack *s, int res[], int len);
void    print_queue_ab(t_stack *s); // delete

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

void	execute(t_stack *s, char *newact);

int		chk_execute(t_stack *s, int fd);
int		chk_sort(t_stack *s, int len);