/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:23:25 by seoson            #+#    #+#             */
/*   Updated: 2023/06/21 15:23:54 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;

	if (!*stack_b)
		return ;
	ft_lstadd_back(&(*stack_a), (*stack_b)->data);
	last = ft_lstlast(*stack_a);
	if (!last)
	{
		last->next = (*stack_a)->next;
		(*stack_a)->next = NULL;
		(*stack_a) = last;
	}
	write(1, "pa\n", 3);
}