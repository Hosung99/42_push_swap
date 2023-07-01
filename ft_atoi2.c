/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:29:20 by seoson            #+#    #+#             */
/*   Updated: 2023/07/01 20:01:36 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	jump_blank(const char *nptr, int *minus_check, int *double_check)
{
	int	i;

	i = 0;
	while ((nptr[i] == 32 || ((nptr[i] >= 9 && nptr[i] <= 13))))
		i++;
	while (nptr[i])
	{
		if (nptr[i] == '-')
			*minus_check = *minus_check + 1;
		else if (nptr[i] == '+')
			*double_check = *double_check + 1;
		else
			break ;
		i++;
	}
	return (i);
}

long long	ft_atoi2(char *nptr)
{
	int			i;
	int			minus_check;
	int			double_check;
	long long	sum;

	minus_check = 0;
	double_check = 0;
	sum = 0;
	i = jump_blank(nptr, &minus_check, &double_check);
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
				sum = sum * 10 + (nptr[i] - 48);
		else
			break ;
		i++;
	}
	if (double_check + minus_check > 1)
		return (0);
	else if (minus_check == 1)
		return (sum * -1);
	else
		return (sum);
}
