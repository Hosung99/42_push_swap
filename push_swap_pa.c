/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:23:25 by seoson            #+#    #+#             */
/*   Updated: 2023/08/05 18:32:26 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*temp;

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
	temp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	free(temp);
	write(1, "pa\n", 3);
}
