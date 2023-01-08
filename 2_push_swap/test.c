
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>
#include "push_swap.h"

// unsigned int	*pre_sort(int draft[], int len)
// {
// 	unsigned int	zero;
// 	int				arr_p[2147483647];
// 	int				arr_n[2147483647];
// 	unsigned int	*arr2;
// 	int				i;

// 	i = 0;
// 	ft_bzero(arr_p, 2147483647);
// 	ft_bzero(arr_n, 2147483647);
// 	arr2 = ft_calloc(len, sizeof(int));
// 	if (!arr2)
// 		return (0);
// 	while (i < len)
// 	{
// 		if (draft[i] == 0)
// 			zero = i;
// 		arr1[draft[i]] = i;
// 		i++;
// 		if 
// 	}
// 	i = 0;
// 	while (i < len)
// 	{
// 		arr2[i] = arr1[draft[i]];
// 		i++;
// 	}
// 	// free(draft);
// 	return (arr2);
// }

int main(int ac, char **av)
{
	//pretreat
	// int val[] = {-1, 3, 4, -5, 6, 2,-7,8,-20,10, 9, 11, -8, 0, -3};
	int *res;
	t_pre_val	*pre;
	t_stack		s;
	int len = ac - 1;

	if (ac <= 2)
		return (0);

	res = malloc(sizeof(int) * (ac -1));
	if (!res)
		return (0);
	pre = atoi_arr(ac -1, av + 1, res);
	pre_quick_sort(pre, 0, len);
	indexing(pre, res, len);

	init_stack(&s, res, len);

	mergesort_atop(&s, 1, len);
	// print_queue_ab(&s);

	// printf("sssssssssssssssssssssssssss\n\n");
	// print_queue_ab(&s);
	// execute(NULL, NULL);
	free(res);
	// pri_all_sort(&s, ac -1);
}



