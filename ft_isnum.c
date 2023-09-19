/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:43:32 by seoson            #+#    #+#             */
/*   Updated: 2023/09/12 13:26:51 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *argv)
{
	int			index;
	int			minus_flag;

	index = 0;
	minus_flag = 0;
	while (argv[index])
	{
		if (argv[index] == '-')
		{
			minus_flag++;
			if (minus_flag == 2 || !argv[index + 1])
				return (0);
			index++;
			continue ;
		}
		if (!(argv[index] >= '0' && argv[index] <= '9')
			|| ft_check_int(ft_atoi2(argv)))
			return (0);
		index++;
	}
	return (1);
}
