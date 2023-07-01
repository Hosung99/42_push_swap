/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:43:32 by seoson            #+#    #+#             */
/*   Updated: 2023/07/01 20:01:30 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(long long argv)
{
	if (argv > 2147483647)
		return (1);
	else if (argv < -2147483648)
		return (1);
	else
		return (0);
}

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
			if (minus_flag == 2 || !(argv[index + 1] > '0' && argv[index + 1] < '9'))
				return (0);
			index++;
			continue ;
		}
		if (!(argv[index] >= '0' && argv[index] <= '9') || check_int(ft_atoi2(argv)))
			return (0);
		index++;
	}
	return (1);
}
