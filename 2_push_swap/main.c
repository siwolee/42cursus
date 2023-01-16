
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	s;
	unsigned int		len;

	len = ac - 1;
	if (ac <= 2)
		return (0);
	pretreat(&s, av + 1, ac - 1);
	sort_merge4(&s, 1, len, ATOP);
	optimization(s.act);
	print_final(&s);
	free_stack(&s);
}



