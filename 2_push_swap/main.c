
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	s;

	if (ac <= 2)
		return (0);
	pretreat(&s, av + 1, ac - 1);
	mergesort_atop(&s, 1, ac - 1);
	free_stack(&s);
}



