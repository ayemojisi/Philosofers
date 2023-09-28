/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_value_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:28:28 by iergun            #+#    #+#             */
/*   Updated: 2023/09/21 16:49:58 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

t_philo	*philo_args_value(int ac, char **av, t_philo *philo)
{
	philo->total_philo = ft_ato(av[1]);
	philo->die_time = ft_ato(av[2]);
	philo->eat_time = ft_ato(av[3]);
	philo->sleep_time = ft_ato(av[4]);
	philo->start_time = get_time();
	philo->died_philo = 0;
	philo->number1 = 0;
	if (ac == 6)
		philo->eat_count = ft_ato(av[5]);
	else
		philo->eat_count = -1;
	return (philo);
}
