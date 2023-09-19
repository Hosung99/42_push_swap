/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:05:34 by seoson            #+#    #+#             */
/*   Updated: 2023/09/11 18:36:42 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list) * 1);
	if (!node)
		return (0);
	node->data = data;
	node->index = 1;
	node->stack_a_cnt = 0;
	node->stack_b_cnt = 0;
	node->stack_total_cnt = 0;
	node->next = NULL;
	return (node);
}
