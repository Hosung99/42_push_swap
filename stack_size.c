/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:19:11 by seoson            #+#    #+#             */
/*   Updated: 2023/07/01 20:34:27 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list *stack_a)
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
