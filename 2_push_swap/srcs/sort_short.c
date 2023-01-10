/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 11:32:05 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/10 19:35:58 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_short(t_stack *s, int size, char ab)
{
	if (ab == ATOP && pri_sort(s, size, ab))
		return ;
	// printf("\033[31msort_short :: %d\n%s", size, C_RS);
	if (size == 2)
		sort_two(s, ab);
	if (size == 3)
	{
		sort_three(s, ab);
		return ;
	}
	if (size == 4)
		return (sort_four(s, ab));
}

void	sort_two(t_stack *s, char ab)
{
	// printf("%ssort two: %d\n%s", C_PINK, ab, C_RS);
	if (ab == ATOP)
	{
		if (s->atop->val > s->atop->next->val)
			execute(s, "1");
	}
	else if (ab == ABOT)
	{
		if (s->abot->val < s->abot->prev->val)
			return (execute(s, "771"));
		else
		{
			return (execute(s, "77"));
		}
	}
	else if (ab == BTOP)
	{
		if (s->btop->val > s->btop->next->val)
			return (execute(s, "33"));
		else
			return (execute(s, "331"));
	}
	else if (ab == BBOT)
	{
		if (s->bbot->val < s->bbot->prev->val)
			return (execute(s, "8833"));
		else
			return (execute(s, "8383"));
	}
}
void	sort_four(t_stack *s, char ab)
{
	t_node *a;
	int	val[4];
	int max[2];
	int i;

	max[0] = 0;
	if (ab == ATOP)
		a = s->atop;
	else if (ab == BTOP)
		a = s->btop;
	else if (ab == ABOT)
		a = s->abot;
	else if (ab == BBOT)
		a = s->bbot;
	else
	{
		// pri_callerr("sort_four");
		return ;
	}
	i = -1;
	while (++i < 4)
	{
		val[i] = a->val;
		if (max[0] < val[i])
		{
			max[1] = i;
			max[0] = val[i];
		}
		if (ab <= BTOP)
			a = a->next;
		else
			a = a->prev;
	}
	// printf("\033[31msort_four :: %d\n%s", max[1], C_RS);
	if (max[1] == 0)
		return (sort_four_4xxx(s, val, ab));
	if (max[1] == 1)
		return (sort_four_x4xx(s, val, ab));
	if (max[1] == 2)
		return (sort_four_xx4x(s, val, ab));
	else
		return (sort_four_xxx4(s, val, ab));
}

void	sort_four_4xxx(t_stack *s, int val[], char ab)
{
	if (ab == ATOP)
	{
		if (val[1] < val[3])
		{
			execute(s, "54447");
			compare_three(s, val[3], val[2], val[1], BTOP);
		}
		else
		{
			execute(s, "45553");
			compare_three(s, val[3], val[2], val[1], ABOT);
		}
	}
	else if (ab == BTOP)
	{
		execute(s, "3");
		compare_three(s, val[1], val[2], val[3], ab);
	}
	else if (ab == ABOT)
	{
		execute(s, "7");
		compare_three(s, val[1], val[2], val[3], ab);
	}
	else //ab == BBOT)
	{
		execute(s, "83");
		compare_three(s, val[1], val[2], val[3], ab);
	}
}

void	sort_four_x4xx(t_stack *s, int val[], char ab)
{
	if (ab == ATOP)
	{
		if (val[0] < val[3])
		{
			execute(s, "45447");
			compare_three(s, val[3], val[2], val[0], BTOP);
		}
		else
		{
			execute(s, "54553");
			compare_three(s, val[3], val[2], val[0], ABOT);
		}
	}
	else if (ab == BTOP)
	{
		execute(s, "23");
		compare_three(s, val[0], val[2], val[3], ab);
	}
	else if (ab == ABOT)
	{
		execute(s, "7715");
		compare_three(s, val[0], val[2], val[3], ab);
	}
	else //ab == BBOT)
	{
		execute(s, "8836");
		compare_three(s, val[0], val[2], val[3], ab);
		
	}
}
void	sort_four_xx4x(t_stack *s, int val[], char ab)
{
	if (ab == ATOP)
	{
		execute(s, "44133");
		compare_three(s, val[0], val[1], val[3], ab);
	}
	else if (ab == BTOP)
	{
		execute(s, "6238");
		compare_three(s, val[0], val[1], val[3], ab);
	}
	else if (ab == ABOT)
	{
		execute(s, "7474774");
		compare_three(s, val[3], val[1], val[0], BTOP);
	}
	else //ab == BBOT)
	{
		execute(s, "88838");
		compare_three(s, val[3], val[1], val[0], BTOP);
	}
}

void	sort_four_xxx4(t_stack *s, int val[], char ab)
{
	if (ab == ATOP)
	{
		compare_three(s, val[0], val[1], val[2], ab);
	}
	else if (ab == BTOP)
	{
		execute(s, "6663");
		compare_three(s, val[2], val[1], val[0], BBOT);
	}
	else if (ab == ABOT)
	{
		execute(s, "7774447");
		compare_three(s, val[0], val[1], val[2], BTOP);
	}
	else //ab == BBOT)
	{
		execute(s, "88883");
		compare_three(s, val[2], val[1], val[0], BTOP);
	}
}

void	sort_three(t_stack *s, char ab)
{
	t_node *a;
	t_node *b;
	t_node *c;

	if (ab == ATOP)
		a = s->atop;
	else if (ab == BTOP)
		a = s->btop;
	else if (ab == ABOT)
		a = s->abot;
	else if (ab == BBOT)
		a = s->bbot;
	else
	{
		// printf("error on chk_three\n");
		return ;
	}
	if (ab <= BTOP)
	{
		b = a->next;
		c = b->next;
	}
	else
	{
		b = a->prev;
		c = b->prev;
	}
	return (compare_three(s, a->val, b->val, c->val, ab));
}

void	compare_three(t_stack *s, int a, int b, int c, char ab)
{
	if (a < b)
	{
		if (c < a)
			return (sort_three_231(s, ab));
		else if (b < c)
			return (sort_three_123(s, ab));
		else //(a < c && c < b)
			return (sort_three_132(s, ab));
	}
	else//(b < a)
		if (a < c)
			return (sort_three_213(s, ab));
		else if (c < b)
			return (sort_three_321(s, ab));
		else //(b < c && c < a)
			return (sort_three_312(s, ab));
}

void	sort_three_123(t_stack *s, char ab)
{
	// printf("\033[31msort_3 :: 123\n%s", C_RS);
	if (ab == ATOP)
	{
		return ;
	}
	else if (ab == ABOT)
	{
		return (execute(s, "747713"));
	}
	else if (ab == BTOP)
	{
		return (execute(s, "623383"));
	}
	else if (ab == BBOT)
	{
		return (execute(s, "888333"));//ok
	}
}

void	sort_three_132(t_stack *s, char ab)
{
	// printf("\033[31msort_3 :: 132\n%s", C_RS);
	if (ab == ATOP)
	{
		return (execute(s, "413"));
	}
	else if (ab == BTOP)//ok
	{
		return (execute(s, "63383"));
	}
	else if (ab == ABOT) //ok
	{
		return (execute(s, "771473"));
	}
	else if (ab == BBOT)
	{
		return (execute(s, "883833"));
	}
}

void	sort_three_213(t_stack *s, char ab)
{
	// printf("\033[31msort_3 :: 213\n%s", C_RS);
	if (ab == ATOP)
	{
		return (execute(s, "1"));
	}
	else if (ab == BTOP)
	{
		return (execute(s, "32313"));
	}
	else if (ab == ABOT) 
	{
		return (execute(s, "774713"));
	}
	else if (ab == BBOT)
	{
		return (execute(s, "8388313"));
	}
}

void	sort_three_231(t_stack *s, char ab)
{
	// printf("\033[31msort_3 :: 231\n%s", C_RS);
	if (ab == ATOP)
	{
		return (execute(s, "5171"));
	}
	else if (ab == BTOP)
	{
		return (execute(s, "3313"));
	}
	else if (ab == ABOT) //ok
	{
		return (execute(s, "7717"));
	}
	else if (ab == BBOT)
	{
		return (execute(s, "883383"));
	}
}

void	sort_three_312(t_stack *s, char ab)
{
	// printf("\033[31msort_3 :: 312\n%s", C_RS);
	if (ab == ATOP)
	{
		return (execute(s, "455377"));
	}
	else if (ab == BTOP)
	{
		return (execute(s, "3331"));
	}
	else if (ab == ABOT)
	{
		return (execute(s, "77473"));
	}
	else if (ab == BBOT)
	{
		return (execute(s, "838833"));
	}
}

void	sort_three_321(t_stack *s, char ab)
{
	// printf("\033[31msort_3 :: 321\n%s", C_RS);
	if (ab == ATOP)
	{
		return (execute(s, "415317"));
	}
	else if (ab == BTOP)
	{
		return (execute(s, "333"));
	}
	else if (ab == ABOT)
	{
		return (execute(s, "777"));
	}
	else if (ab == BBOT)
	{
		return (execute(s, "838383"));
	}
}
