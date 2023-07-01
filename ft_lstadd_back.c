/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:40:07 by seoson            #+#    #+#             */
/*   Updated: 2023/06/23 14:19:44 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, int data)
{
	t_list	*last;
	t_list	*temp;

	if (!*lst)
		*lst = ft_lstnew(data);
	else
	{
		last = ft_lstlast(*lst);
		temp = ft_lstnew(data);
		last->next = temp;
		temp->next = NULL;
		//temp->prev = last;
	}
}
