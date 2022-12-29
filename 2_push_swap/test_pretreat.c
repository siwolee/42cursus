
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <time.h>

unsigned int	*pre_sort(int draft[], int len)
{
	unsigned int	idx;
	int				arr1[20000000];
	unsigned int	*arr2;
	int				i;

	i = 0;
	arr2 = ft_calloc(len, sizeof(int));
	if (!arr2)
		return (0);
	while (i < len)
	{
		arr1[draft[i]] = i;
		i++;
	}
	i = 0;
	while (i < len)
	{
		arr2[i] = arr1[draft[i]];
		i++;
	}
	// free(draft);
	return (arr2);
}

void	pre_quick_sort(int *data, int start, int end)
{
	// int	*res;
	int	i;
	int	j;
	int	pivot;
	int	temp;

	// res = ft_calloc(end, sizeof(int));
	pivot = 0;
	i = 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && data[i] <= data[pivot])
		{
			i++;
		}
		while (j > start && data[j] >= data[pivot])
		{
			j--;
		}
		if (i > j)
		{
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	if (i > j)
		return ;
	pre_quick_sort(data, start, j - 1);
    pre_quick_sort(data, j + 1, end);
}


int main()
{
	int pre[] = {9, 10, 35648932, -4512321, 121, 111 , 139, 0, 2, 1238437, 1298, 2938, -3};
	// unsigned int *just;
	int *quick; 

	// clock_t begin = clock();

	// just = pre_sort(pre, 13);
	pre_quick_sort(pre, 0, 12);	

	// clock_t end = clock();
	// double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	// printf("%f sec on justsort\n", time_spent);
	// free(just); 
	for (int i = 0; i < 12; i++)
	{
		printf("pre 1 = %d\n", pre[i]);
	}


}

