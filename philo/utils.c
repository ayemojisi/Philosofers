/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:56:54 by iergun            #+#    #+#             */
/*   Updated: 2023/09/23 00:00:45 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_digitlan(int c)
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
			sign = -1;
		i++;
	}
	while (ft_digitlan(str[i]))
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

t_time	ft_get_time(void)
{
	struct timeval		tv;
	unsigned long long	time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

int	ft_arg(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 5 && ac != 6)
		return (ERROR42);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (ERROR42);
			if (ft_ato(av[i]) > MAX)
				return (ERROR42);
			if (ft_ato(av[i]) == 0)
				return (ERROR42);
			j++;
		}
		i++;
	}
	return (1);
}
