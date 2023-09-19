/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_desc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:57:44 by seoson            #+#    #+#             */
/*   Updated: 2023/09/13 13:52:40 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_desc(t_list **stack_a)
{
	t_list	*temp;
	int		index;

	temp = (*stack_a);
	index = (*stack_a)->index;
	while (temp)
	{
		if (temp->index != index)
			return (0);
		index--;
		temp = temp->next;
	}
	return (1);
}
