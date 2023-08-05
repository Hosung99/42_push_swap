/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_over_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:07:58 by seoson            #+#    #+#             */
/*   Updated: 2023/08/05 19:07:40 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pivot_1(t_list *stack_a)
{
	int		pivot_1;
	t_list	*temp;

	pivot_1 = 0;
	temp = stack_a;
	while (temp)
	{
		if (temp->data > pivot_1)
			pivot_1 = temp->data;
		temp = temp->next;
	}
	return (pivot_1 / 3);
}

static int	get_pivot_2(t_list *stack_a)
{
	int		pivot_2;
	t_list	*temp;

	pivot_2 = 0;
	temp = stack_a;
	while (temp)
	{
		if (temp->data > pivot_2)
			pivot_2 = temp->data;
		temp = temp->next;
	}
	return (pivot_2 / 3 * 2);
}

void	sort_over_3(t_list **stack_a, t_list**stack_b)
{
	t_list	*temp;

	temp = (*stack_a);
	while (stack_size((*stack_a)) > 3)
	{
		if (temp->data <= get_pivot_1(*stack_a))
		{
			pb(&(*stack_a), &(*stack_b));
			rb(&(*stack_b), 1);
		}
		else if ((temp->data > get_pivot_1(*stack_a)) && (temp->data <= get_pivot_2(*stack_a))) 
			pb(&(*stack_a), &(*stack_b));
		else
			ra(&(*stack_a), 1);
	}
	sort(&(*stack_a), &(*stack_b));
	t_list *temp_a;
	t_list *temp_b;
	temp_a = (*stack_a);
	temp_b = (*stack_b);
	printf("stack :A------------------------\n");
	while (temp_a)
	{
		printf("%d\n",temp_a->data);
		temp_a = temp_a->next;
	}
	printf("stack :B------------------------\n");
	while (temp_b)
	{
		printf("%d\n",temp_b->data);
		temp_b = temp_b->next;
	}
	printf("b size: %d",stack_size(*stack_b) / 2);
}
