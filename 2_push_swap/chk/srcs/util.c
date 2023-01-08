/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:35:54 by siwolee           #+#    #+#             */
/*   Updated: 2023/01/09 00:52:29 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chker.h"

int	chk_execute(t_stack *s, int fd)
{
	char	*x;

	while ((x = get_next_line(fd)))
	{
		if (x[0] == 's' && x[1] == 'a' && x[2] == '\n')
			sa(s);
		else if (x[0] == 's' && x[1] == 'b' && x[2] == '\n')
			sb(s);
		else if (x[0] == 'p' && x[1] == 'a' && x[2] == '\n')
			pa(s);
		else if (x[0] == 'p' && x[1] == 'b' && x[2] == '\n')
			pb(s);
		else if (x[0] == 'r' && x[1] == 'a' && x[2] == '\n')
			ra(s);
		else if (x[0] == 'r' && x[1] == 'b' && x[2] == '\n')
			rb(s);
		else if (x[0] == 'r' && x[1] == 'r' && x[2] == 'a' && x[3] == '\n')
			rra(s);
		else if (x[0] == 'r' && x[1] == 'r' && x[2] == 'b' && x[3] == '\n')
			rrb(s);
		else if (x[0] == 's' && x[1] == 's' && x[2] == '\n')
			execute(s, "91");
		else if (x[0] == 'r' && x[1] == 'r' && x[2] == '\n')
			execute(s, "92");
		else if (x[0] == 'r' && x[1] == 'r' && x[2] == 'r' && x[3] == '\n')
			execute(s, "93");
		// else
		// {
		// 	free (x);
		// 	return (1);
		// }
		free(x);
	}
	return (0);
}

int	chk_sort(t_stack *s, int len)
{
	int		i;
	int		bf;
	t_node	*n;

	if (s->btop || !s->atop)
		return (1);
	i = 0;
	n = s->atop;
	bf = s->atop->val;
	while (n->next)
	{
		n = n->next;
		if (bf >= n->val)
		{
			printf("error-> %d %d \n", bf, n->val);
			return (1);
		}
		bf = n->val;
		i++;
	}
	printf("GOOD\n");
	if (i == len)
		return (0);
	else
		return (1);
}
