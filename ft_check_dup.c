/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:57:59 by seoson            #+#    #+#             */
/*   Updated: 2023/09/13 21:59:50 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_dup(t_list **stack_a)
{
	t_list	*outer_loop;
	t_list	*inner_loop;

	outer_loop = (*stack_a);
	while (outer_loop->next)
	{
		inner_loop = outer_loop->next;
		while (inner_loop)
		{
			if (outer_loop->data == inner_loop->data)
			{
				write(2, "Error\n", 6);
				ft_lstclear(&(*stack_a));
				exit(1);
			}
			inner_loop = inner_loop->next;
		}
		outer_loop = outer_loop->next;
	}
}
