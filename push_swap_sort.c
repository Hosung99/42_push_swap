/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:53:45 by seoson            #+#    #+#             */
/*   Updated: 2023/08/05 19:06:46 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort2(t_list **head)
{
	if ((*head)->next->data < (*head)->data)
		ra(&(*head), 0);
}

static void	sort3(t_list **head)
{
	int	second;
	int	third;

	second = (*head)->next->data;
	third = (*head)->next->next->data;
	if ((third < second) && (third < (*head)->data))
	{
		if ((*head)->data > second)
		{
			sa(&(*head), 1);
			rra(&(*head), 1);
		}
		else
			rra(&(*head), 1);
	}
	else if ((*head)->data > third)
		ra(&(*head), 1);
	else if ((*head)->data > second)
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

	cnt = stack_size(*stack_a);
	if (cnt == 0 || cnt == 1)
		return ;
	else if (cnt == 2)
		sort2(&(*stack_a));
	else if (cnt == 3)
		sort3(&(*stack_a));
	else
		sort_over_3(&(*stack_a), &(*stack_b));
}
