/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_greedy_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:13:47 by seoson            #+#    #+#             */
/*   Updated: 2023/09/14 18:35:06 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_greedy_sort(t_list **temp, t_list **stack_a, t_list **stack_b,
int min_val)
{
	while (temp)
	{
		if ((*temp)->stack_total_cnt == min_val)
		{
			if ((*temp)->stack_b_cnt > 0)
				while ((*temp)->stack_b_cnt-- > 0)
					rb(&(*stack_b), 1);
			else
				while ((*temp)->stack_b_cnt++ < 0)
					rrb(&(*stack_b), 1);
			if ((*temp)->stack_a_cnt > 0)
				while (--(*temp)->stack_a_cnt > 0)
					ra(&(*stack_a), 1);
			else
				while ((*temp)->stack_a_cnt++ < 0)
					rra(&(*stack_a), 1);
			pa(&(*stack_a), &(*stack_b));
			break ;
		}
		(*temp) = (*temp)->next;
	}
}

void	greedy_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		min_val;

	temp = (*stack_b);
	min_val = 2147483647;
	while (temp)
	{
		temp->stack_total_cnt = abs(temp->stack_a_cnt) + abs(temp->stack_b_cnt);
		if (temp->stack_total_cnt < min_val)
			min_val = temp->stack_total_cnt;
		temp = temp->next;
	}
	temp = (*stack_b);
	do_greedy_sort(&temp, &(*stack_a), &(*stack_b), min_val);
}
