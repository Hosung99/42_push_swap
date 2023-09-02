/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_over_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:07:58 by seoson            #+#    #+#             */
/*   Updated: 2023/09/02 14:05:27 by seoson           ###   ########.fr       */
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

void	count_command_b(t_list **stack_b)
{
	t_list	*temp;
	int		minus_index;
	int		node_index;
	int		half_index;

	node_index = 0;
	minus_index = 1;
	half_index = stack_size(*stack_b) / 2;
	temp = (*stack_b);
	while (temp)
	{
		if (node_index > half_index - 1)
		{
			temp->stack_b_cnt = node_index - minus_index;
			minus_index++;
		}
		else
		{
			temp->stack_b_cnt = node_index;
			node_index++;
		}
		temp = temp->next;
	}
}

void	count_command_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		half_index;
	
	temp = (*stack_b);
	half_index = stack_size(*stack_a) / 2;
	while (temp)
	{
		if (check_bigger(&(*stack_a), temp))
			temp->stack_a_cnt = set_bigger(&(*stack_a), temp);
		else
			set_smaller(&(*stack_a), &temp);
		temp = temp->next;
	}
}

int	check_bigger(t_list **stack_a, t_list *stack_b)
{
	t_list	*temp;
	int		bigger_flag;
	
	bigger_flag = 0;
	temp = (*stack_a);
	while (temp)
	{
		if (temp->data > stack_b->data)
			bigger_flag = 1;
		temp = temp->next;
	}
	return bigger_flag;
}

int	set_bigger(t_list **stack_a, t_list *stack_b)
{
	t_list	*temp;
	int		temp_number;
	int		index;
	int		half_index;

	temp = (*stack_a);
	temp_number = 2147483647;
	index = 1;
	half_index = stack_size(*stack_a) / 2;
	while (temp)
	{
		if (temp->data > stack_b->data && temp->data < temp_number)
			temp_number = temp->data;
		temp = temp->next;
	}
	temp = (*stack_a);
	while (temp)
	{
		if (temp->data == temp_number)
			return index;
		temp = temp->next;
		index++;
	}
	return (0);
}

void	set_smaller(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		index;
	int		min_val;
	
	index = 0;
	min_val = 2147483647;
	temp = (*stack_a);
	while (temp)
	{
		if (min_val > temp->data)
			min_val = temp->data;
		temp = temp->next;
	}
	temp = (*stack_b);
	while (temp)
	{
		if (temp->data == min_val)
			temp->stack_a_cnt = index;
		temp = temp->next;
		index++;
	}
}

void	greedy_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		min_cnt;

	temp = (*stack_b);
	min_cnt = 2147483647;
	while (temp)
	{
		temp->stack_total_cnt = temp->stack_a_cnt + temp->stack_b_cnt;
			// printf("stack data: %d , stack_total_cnt : %d\n", temp->data ,temp->stack_a_cnt);
			// printf("stack data: %d , stack_total_cnt : %d\n", temp->data ,temp->stack_b_cnt);
		if (temp->stack_total_cnt < min_cnt)
			min_cnt = temp->stack_total_cnt;
		temp = temp->next; 
	}
	temp = (*stack_b);
	while (temp)
	{
		if (temp->stack_total_cnt == min_cnt)
		{
			printf("stack data: %d , stack_total_cnt : %d\n", temp->data ,temp->stack_total_cnt);
			while (--temp->stack_b_cnt > 0)
				rb(&(*stack_b), 1);
			while (--temp->stack_a_cnt > 0)
				ra(&(*stack_a), 1);
			pa(&(*stack_a), &(*stack_b));
			break ;
		}
		temp = temp->next;
	}
}

void	sort_over_3(t_list **stack_a, t_list **stack_b)
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
		{
			ra(&(*stack_a), 1);
			temp = temp->next;
		}
	}
	sort(&(*stack_a), &(*stack_b));
	t_list *temp_a;
	t_list *temp_b;
	temp_a = (*stack_a);
	printf("stack :A------------------------\n");
	while (temp_a)
	{
		printf("%d\n",temp_a->data);
		temp_a = temp_a->next;
	}
	printf("stack :B------------------------\n");
	temp_b = (*stack_b);
	while (temp_b)
	{
		printf("%d\n",temp_b->data);
		temp_b = temp_b->next;
	}

		count_command_b(&(*stack_b));
		count_command_a(&(*stack_a), &(*stack_b));
		greedy_sort(&(*stack_a), &(*stack_b));

	temp_a = (*stack_a);
	printf("stack :A------------------------\n");
	while (temp_a)
	{
		printf("%d\n",temp_a->data);
		temp_a = temp_a->next;
	}
	printf("stack :B------------------------\n");
	temp_b = (*stack_b);
	while (temp_b)
	{
		printf("%d\n",temp_b->data);
		temp_b = temp_b->next;
	}


count_command_b(&(*stack_b));
		count_command_a(&(*stack_a), &(*stack_b));
		greedy_sort(&(*stack_a), &(*stack_b));

	temp_a = (*stack_a);
	printf("stack :A------------------------\n");
	while (temp_a)
	{
		printf("%d\n",temp_a->data);
		temp_a = temp_a->next;
	}
	printf("stack :B------------------------\n");
	temp_b = (*stack_b);
	while (temp_b)
	{
		printf("%d\n",temp_b->data);
		temp_b = temp_b->next;
	}

	count_command_b(&(*stack_b));
		count_command_a(&(*stack_a), &(*stack_b));
		greedy_sort(&(*stack_a), &(*stack_b));

	temp_a = (*stack_a);
	printf("stack :A------------------------\n");
	while (temp_a)
	{
		printf("%d\n",temp_a->data);
		temp_a = temp_a->next;
	}
	printf("stack :B------------------------\n");
	temp_b = (*stack_b);
	while (temp_b)
	{
		printf("%d\n",temp_b->data);
		temp_b = temp_b->next;
	}

		count_command_b(&(*stack_b));
		count_command_a(&(*stack_a), &(*stack_b));
		greedy_sort(&(*stack_a), &(*stack_b));

	temp_a = (*stack_a);
	printf("stack :A------------------------\n");
	while (temp_a)
	{
		printf("%d\n",temp_a->data);
		temp_a = temp_a->next;
	}
	printf("stack :B------------------------\n");
	temp_b = (*stack_b);
	while (temp_b)
	{
		printf("%d\n",temp_b->data);
		temp_b = temp_b->next;
	}


		count_command_b(&(*stack_b));
		count_command_a(&(*stack_a), &(*stack_b));
		greedy_sort(&(*stack_a), &(*stack_b));

	temp_a = (*stack_a);
	printf("stack :A------------------------\n");
	while (temp_a)
	{
		printf("%d\n",temp_a->data);
		temp_a = temp_a->next;
	}
	printf("stack :B------------------------\n");
	temp_b = (*stack_b);
	while (temp_b)
	{
		printf("%d\n",temp_b->data);
		temp_b = temp_b->next;
	}
}

