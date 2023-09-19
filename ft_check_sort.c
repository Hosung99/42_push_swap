/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:14:57 by seoson            #+#    #+#             */
/*   Updated: 2023/09/12 13:00:35 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_sort(t_list **stack_a)
{
	t_list	*temp;
	int		index;

	temp = (*stack_a);
	index = 1;
	if (temp->index != index)
	{
		while (temp)
		{
			if (temp->index == 1)
				break ;
			index++;
			temp = temp->next;
		}
	}
	if (index > ft_stack_size(*stack_a) / 2)
	{
		while ((*stack_a)->index != 1)
			rra(&(*stack_a), 1);
	}
	else
	{
		while ((*stack_a)->index != 1)
			ra(&(*stack_a), 1);
	}
}
