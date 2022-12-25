/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:50:34 by siwolee           #+#    #+#             */
/*   Updated: 2022/12/22 20:30:15 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"


//test1
// int	main()
// {
// 	t_stack	*a;
// 	t_stack *b;
// 	int temp[] = {2, 1, 3, 6, 5, 8, -1};

// 	a= 0;
// 	b=0;
// 	if (!init_stack(temp, &a) || !init_stack(0, &b))
// 		return (0);
// 	print_stack(a);
// 	s(a);
// 	print_stack(a);
// 	p(b, a), p(b, a), p(b, a);
// 	print_stack(a);
// 	r(a), r(b);
// 	print_stack(a);
// 	rr(a), rr(b);
// 	print_stack(a);
// 	s(a);
// 	print_stack(a);
// 	p(a, b), p(a, b), p(a, b);
// 	print_stack(a);
// }

int main()
{
	t_stack	a;
	t_stack b;

	int temp[] = {2, 1, 3, 6, 5, 8, -1};

	init_stack(temp, 7, &a);

	tempsort(&a, &b);
}