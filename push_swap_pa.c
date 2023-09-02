/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:23:25 by seoson            #+#    #+#             */
/*   Updated: 2023/09/02 13:48:39 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b)
		return ;
	temp = (*stack_b);
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_a);
	(*stack_a) = temp;
	write(1, "pa\n", 3);
}
