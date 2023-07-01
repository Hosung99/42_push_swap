/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:45:59 by seoson            #+#    #+#             */
/*   Updated: 2023/07/01 20:24:54 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **head, int flag)
{
	t_list	*last;
	t_list	*temp;

	if (!*head || (*head)->next == NULL)
		return ;
	temp = *head;
	last = ft_lstlast(temp);
	*head = temp->next;
	last->next = temp;
	temp->next = NULL;
	if (flag)
		write(1,"ra\n",3);
}
