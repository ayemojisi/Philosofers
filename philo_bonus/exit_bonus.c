/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:28:52 by iergun            #+#    #+#             */
/*   Updated: 2023/09/28 00:13:13 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_exit(t_philo *philo)
{
	int	i;
	int	j;
	int	f;
	int	d;

	d = 0;
	i = -1;
	waitpid(-1, &f, 0);
	j = -1;
	while (++j < philo->total_philo)
		kill(philo->eternald[j].id, 15);
	sem_close(philo->died);
	sem_close(philo->forks);
	sem_close(philo->printf);
	sem_unlink("/printf");
	sem_unlink("/forks");
	sem_unlink("/died");
	free(philo->eternald);
	free(philo);
}
