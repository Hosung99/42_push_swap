/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_over_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:07:58 by seoson            #+#    #+#             */
/*   Updated: 2023/09/13 14:18:00 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_stack_a_3(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	i;
	int	pivot_1;

	size = ft_stack_size(*stack_a);
	i = 0;
	pivot_1 = size / 3;
	if (size <= 5)
		pivot_1 = 3;
	while (i++ < size - 3)
	{
		if ((*stack_a)->index <= pivot_1)
		{
			pb(&(*stack_a), &(*stack_b));
			rb(&(*stack_b), 1);
		}
		else if (((*stack_a)->index > pivot_1)
			&& ((*stack_a)->index <= pivot_1 * 2))
			pb(&(*stack_a), &(*stack_b));
		else
			ra(&(*stack_a), 1);
	}
	size = ft_stack_size(*stack_a);
	while (size-- > 3)
		pb(&(*stack_a), &(*stack_b));
}

void	sort_over_3(t_list **stack_a, t_list **stack_b)
{
	set_stack_a_3(&(*stack_a), &(*stack_b));
	sort(&(*stack_a), &(*stack_b));
	while (ft_stack_size((*stack_b)) > 0)
	{
		ft_count_command_b(&(*stack_b));
		ft_count_command_a(&(*stack_a), &(*stack_b));
		greedy_sort(&(*stack_a), &(*stack_b));
	}
	ft_check_sort(&(*stack_a));
}
