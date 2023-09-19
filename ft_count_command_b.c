/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_command_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:06:35 by seoson            #+#    #+#             */
/*   Updated: 2023/09/14 19:26:53 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_count_command_b(t_list **stack_b)
{
	t_list	*temp;
	int		stack_index;
	int		stack_size;
	int		minus_index;

	temp = (*stack_b);
	stack_index = 0;
	stack_size = ft_stack_size(*stack_b);
	minus_index = stack_size / 2;
	if (ft_stack_size(*stack_b) % 2 == 0)
		minus_index--;
	while (temp)
	{
		if (stack_index > stack_size / 2)
		{
			temp->stack_b_cnt = minus_index * -1;
			minus_index--;
		}
		else
		{
			temp->stack_b_cnt = stack_index;
			stack_index++;
		}
		temp = temp->next;
	}
}
