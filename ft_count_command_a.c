/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_command_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:02:35 by seoson            #+#    #+#             */
/*   Updated: 2023/09/14 18:38:15 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_index(t_list **temp, t_list **stack_a, int val)
{
	int		minus_index;
	int		index;
	int		stack_size;

	minus_index = 0;
	index = 0;
	stack_size = ft_stack_size(*stack_a);
	if (stack_size % 2 == 0)
		minus_index++;
	while (temp)
	{
		if (index > stack_size / 2)
			minus_index++;
		else
			index++;
		if ((*temp)->index == val)
		{
			if (index > stack_size / 2)
				index = index * -1 + minus_index;
			return (index);
		}
		temp = &(*temp)->next;
	}
	return (0);
}

static int	check_bigger(t_list **stack_a, t_list *stack_b)
{
	t_list	*temp;
	int		bigger_flag;

	bigger_flag = 0;
	temp = (*stack_a);
	while (temp)
	{
		if (temp->index > stack_b->index)
			bigger_flag = 1;
		temp = temp->next;
	}
	return (bigger_flag);
}

static int	count_bigger(t_list **stack_a, t_list *stack_b)
{
	t_list	*temp;
	int		max_val;

	temp = (*stack_a);
	max_val = 2147483647;
	while (temp)
	{
		if (temp->index > stack_b->index && temp->index < max_val)
			max_val = temp->index;
		temp = temp->next;
	}
	temp = (*stack_a);
	return (count_index(&temp, &(*stack_a), max_val));
}

static int	count_smaller(t_list **stack_a)
{
	t_list	*temp;
	int		min_val;

	temp = (*stack_a);
	min_val = 2147483647;
	while (temp)
	{
		if (min_val > temp->index)
			min_val = temp->index;
		temp = temp->next;
	}
	temp = (*stack_a);
	return (count_index(&temp, &(*stack_a), min_val));
}

void	ft_count_command_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = (*stack_b);
	while (temp)
	{
		if (check_bigger(&(*stack_a), temp))
			temp->stack_a_cnt = count_bigger(&(*stack_a), temp);
		else
			temp->stack_a_cnt = count_smaller(&(*stack_a));
		temp = temp->next;
	}
}
