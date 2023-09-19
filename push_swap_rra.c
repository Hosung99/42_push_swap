/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:07:56 by seoson            #+#    #+#             */
/*   Updated: 2023/09/10 14:48:20 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **head, int flag)
{
	t_list	*last;
	t_list	*last_prev;

	if (!*head || (*head)->next == NULL)
		return ;
	last = *head;
	while (last->next != NULL)
	{
		last_prev = last;
		last = last->next;
	}
	last->next = *head;
	last_prev->next = NULL;
	*head = last;
	if (flag)
		write(1, "rra\n", 4);
}
