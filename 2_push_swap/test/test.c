
# include <stdlib.h>
# include <unistd.h>
// # include "./libft/libft.h"
# include <stdio.h>
# include <time.h>
#include "../include/push_swap.h"

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

int main()
{
	//pretreat
	int val[] = {-1,2,4,-8,-3,0};
	int res[] = {5, 3, 7, 6, 2, 1};
	t_pre_val	pre[8];
	t_stack		s;
	int len = 6;

	for (int i = 0; i < len; i++)
	{
		pre[i].idx = i;
		pre[i].val = val[i];
	}
	pre_quick_sort(pre, 0, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d, ", pre[i].val);
	}
	printf("\n");
	indexing(pre, res, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d, ", res[i]);
	}
	init_stack(&s, res, len);
	print_stack(&s, 0);

	//operation
	mergesort_atop(&s, 1, 6);
}

