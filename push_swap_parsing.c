/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:55:57 by seoson            #+#    #+#             */
/*   Updated: 2023/09/13 21:59:31 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_parsing(int argc, char *argv[], t_list **stack_a)
{
	int		index;
	char	**temp;
	char	**temp_temp;

	index = 1;
	while (--argc)
	{
		temp = ft_split(argv[index++], 32);
		temp_temp = temp;
		while (*temp)
		{
			if (ft_isnum(*temp))
				ft_lstadd_back(&(*stack_a), ft_atoi(*temp));
			else
			{
				write(2, "Error\n", 6);
				ft_lstclear(&(*stack_a));
				exit(1);
			}
			temp++;
		}
		if (temp_temp)
			free(temp_temp);
	}
}
