/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_desc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:54:15 by seoson            #+#    #+#             */
/*   Updated: 2023/09/13 13:55:14 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_desc(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		size;

	temp = (*stack_a);
	size = ft_stack_size(*stack_a) - 3;
	while (size-- > 0)
	{
		rra(&(*stack_a), 1);
		pb(&(*stack_a), &(*stack_b));
	}
	sort(&(*stack_a), &(*stack_b));
	size = ft_stack_size(*stack_b);
	while (size-- > 0)
		pa(&(*stack_a), &(*stack_b));
}
