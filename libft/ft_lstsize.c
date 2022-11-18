/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siwolee <siwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:58 by siwolee           #+#    #+#             */
/*   Updated: 2022/11/18 18:48:31 by siwolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bonus.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		len;

	len = 0;
	if (lst)
	{
		node = lst;
		len = 1;
		while (node->next != 0)
		{
			node = node->next;
			len++;
		}
	}
	return (len);
}
