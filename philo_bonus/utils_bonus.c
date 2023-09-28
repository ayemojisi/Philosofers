/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:27:42 by iergun            #+#    #+#             */
/*   Updated: 2023/09/21 16:49:58 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_digitlan(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	ft_ato(const char *str)
{
	int			i;
	int			sign;
	long long	number;

	sign = 1;
	i = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_digitlan(str[i]) == 1)
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}
