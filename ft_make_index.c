/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:25:29 by seongho           #+#    #+#             */
/*   Updated: 2023/09/12 13:55:10 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_index(t_list **stack_a)
{
	t_list	*outer_loop;
	t_list	*inner_loop;

	ft_check_dup(&(*stack_a));
	outer_loop = (*stack_a);
	while (outer_loop)
	{
		inner_loop = (*stack_a);
		while (inner_loop)
		{
			if (outer_loop->data > inner_loop->data)
				outer_loop->index++;
			inner_loop = inner_loop->next;
		}
		outer_loop = outer_loop->next;
	}
}
