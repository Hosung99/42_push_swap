/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_asc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:28:32 by seoson            #+#    #+#             */
/*   Updated: 2023/09/14 18:30:38 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_asc(t_list **stack_a)
{
	t_list	*temp;
	int		index;

	index = 1;
	temp = (*stack_a);
	while (temp)
	{
		if (temp->index != index)
			return (0);
		index++;
		temp = temp->next;
	}
	return (1);
}
