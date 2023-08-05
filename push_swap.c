/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:17:20 by seoson            #+#    #+#             */
/*   Updated: 2023/08/05 18:41:05 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	char	**temp;
	int 	index;
	t_list	*stack_a;
	t_list	*stack_b;

	index = 1;
	stack_a = NULL;
	while (--argc)
	{
		temp = ft_split(argv[index++], 32);
		while (*temp)
		{
			if (ft_isnum(*temp))
					ft_lstadd_back(&stack_a, ft_atoi(*temp));
			else
			{
				printf("Error\n");
				ft_lstclear(&stack_a);
				return (-1);
			}
			temp++;
		}
	}
	printf("before indexing --------------------------\n");
	t_list *temp_a;
	temp_a = stack_a;
	while (temp_a)
	{
		printf("%d\n",temp_a->data);
		temp_a = temp_a->next;
	}
	make_index(&stack_a);
	printf("after indexing --------------------------\n");
	sort(&stack_a, &stack_b);
	temp_a = stack_a;
/*	while (temp_a)
	{
		printf("%d\n",temp_a->data);
		temp_a = temp_a->next;
	}*/
}
