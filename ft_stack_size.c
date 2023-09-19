/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:19:11 by seoson            #+#    #+#             */
/*   Updated: 2023/09/12 12:53:01 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_list *stack_a)
{
	t_list	*temp;
	int		cnt;

	cnt = 0;
	temp = stack_a;
	while (temp)
	{
		cnt++;
		temp = temp->next;
	}
	return (cnt);
}
