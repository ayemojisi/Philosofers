/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:28:45 by iergun            #+#    #+#             */
/*   Updated: 2023/09/28 01:27:22 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_fork(t_eternalend *eternalend, int total_philo)
{
	int	i;

	i = -1;
	while (++i < total_philo)
	{
		if (i % 2 == 0)
		{
			eternalend[i].id = fork();
			if (eternalend[i].id < 0)
				return (1);
			if (eternalend[i].id == 0)
				proces(&(eternalend[i]));
		}
	}
	if (philo_fork1(eternalend, total_philo) == 1)
		return (1);
	return (0);
}

int	philo_fork1(t_eternalend *eternalend, int total_philo)
{
	int	i;

	i = -1;
	while (++i < total_philo)
	{
		if (i % 2 != 0)
		{
			eternalend[i].id = fork();
			if (eternalend[i].id < 0)
				return (1);
			if (eternalend[i].id == 0)
				proces(&(eternalend[i]));
		}
	}
	return (0);
}

void	*proces(void *sie1)
{
	t_eternalend	*sie;	

	sie = (t_eternalend *)sie1;
	if (sie->philo1->total_philo == 1)
	{
		sem_wait(sie->philo1->forks);
		fork_printf(sie, "has taken a fork");
		wait_time_for(sie->philo1->die_time, sie);
		if (check_death(sie) == 0)
			kill(getpid(), 15);
	}
	while (1)
	{
		eat(sie);
		if (sie->count >= sie->philo1->eat_count \
			&& sie->philo1->eat_count != -1)
			break ;
		fork_printf(sie, "is sleeping");
		wait_time_for(sie->philo1->sleep_time, sie);
		fork_printf(sie, "is thinking");
	}
	exit (0);
}
