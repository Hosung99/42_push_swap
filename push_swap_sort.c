/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:53:45 by seoson            #+#    #+#             */
/*   Updated: 2023/09/13 13:26:29 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort2(t_list **head)
{
	if ((*head)->next->index < (*head)->index)
		rra(&(*head), 1);
}

static void	sort3(t_list **head)
{
	int	second;
	int	third;

	second = (*head)->next->index;
	third = (*head)->next->next->index;
	if ((third < second) && (third < (*head)->index))
	{
		if ((*head)->index > second)
		{
			sa(&(*head), 1);
			rra(&(*head), 1);
		}
		else
			rra(&(*head), 1);
	}
	else if ((*head)->index > third)
		ra(&(*head), 1);
	else if ((*head)->index > second)
		sa(&(*head), 1);
	else if (second > third)
	{
		sa(&(*head), 1);
		ra(&(*head), 1);
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	cnt;

	cnt = ft_stack_size(*stack_a);
	if (cnt == 0 || cnt == 1)
		return ;
	else if (cnt == 2)
		sort2(&(*stack_a));
	else if (cnt == 3)
		sort3(&(*stack_a));
	else if (ft_is_desc(&(*stack_a)))
		ft_sort_desc(&(*stack_a), &(*stack_b));
	else
		sort_over_3(&(*stack_a), &(*stack_b));
}
