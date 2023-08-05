/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:23:25 by seoson            #+#    #+#             */
/*   Updated: 2023/08/05 17:56:22 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*temp;

	if (!*stack_a)
		return ;
	ft_lstadd_back(&(*stack_b), (*stack_a)->data);
	last = ft_lstlast(*stack_b);
	if (!last)
	{
		last->next = (*stack_b)->next;
		(*stack_b)->next = NULL;
		(*stack_b) = last;
	}
	temp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	free(temp);
	write(1, "pb\n", 3);
}
