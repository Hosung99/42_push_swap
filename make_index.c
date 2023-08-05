/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongho <seongho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:25:29 by seongho           #+#    #+#             */
/*   Updated: 2023/08/05 16:08:14 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_index(t_list **stack_a)
{
	int		index;
	t_list	*outer_loop;
	t_list	*inner_loop;
	
	outer_loop = (*stack_a);
	while (outer_loop)
	{
		index = 1;
		inner_loop = (*stack_a);
		while (inner_loop)
		{
			if (outer_loop->data > inner_loop->data)
				index++;
			inner_loop = inner_loop->next;
		}
		outer_loop->data = index;
		outer_loop = outer_loop->next;
	}
}
