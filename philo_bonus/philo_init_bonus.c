/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:28:01 by iergun            #+#    #+#             */
/*   Updated: 2023/09/27 23:50:22 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*philo_init(int ac, char **av)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = NULL;
	philo = (t_philo *)malloc(sizeof(t_philo) * 1);
	philo->total_philo = ft_ato(av[1]);
	sem_unlink("/forks");
	sem_unlink("/died");
	sem_unlink("/printf");
	philo->forks = sem_open("/forks", O_CREAT, S_IRWXU, philo->total_philo);
	philo->died = sem_open("/died", O_CREAT, S_IRWXU, 1);
	philo->printf = sem_open("/printf", O_CREAT, S_IRWXU, 1);
	philo = philo_args_value(ac, av, philo);
	philo->eternald = eternald_info(philo);
	philo_fork(philo->eternald, philo->total_philo);
	return (philo);
}

t_eternalend	*eternald_info(t_philo *philo)
{
	int	i;

	philo->eternald = (t_eternalend *)malloc((sizeof(t_eternalend) \
	* philo->total_philo));
	i = 0;
	while (i < philo->total_philo)
	{
		philo->eternald[i].command = i + 1;
		philo->eternald[i].philo1 = philo;
		philo->eternald[i].eat_last = get_time();
		philo->eternald[i].count = 0;
		philo->eternald[i].is_eating = -1;
		i++;
	}
	return (philo->eternald);
}
