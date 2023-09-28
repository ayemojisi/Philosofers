/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:28:57 by iergun            #+#    #+#             */
/*   Updated: 2023/09/28 01:15:26 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_eternalend *sie)
{
	sem_wait(sie->philo1->forks);
	sem_wait(sie->philo1->forks);
	fork_printf(sie, "has taken a fork");
	fork_printf(sie, "has taken a fork");
	sie->is_eating = 1;
	sie->count += 1;
	sie->eat_last = get_time();
	fork_printf(sie, "is eating");
	wait_time_for(sie->philo1->eat_time, sie);
	sie->is_eating = 0;
	sem_post(sie->philo1->forks);
	sem_post(sie->philo1->forks);
}

void	fork_printf(t_eternalend *sie, char *str)
{
	if (check_death(sie) == 0)
		kill(getpid(), 15);
	sem_wait(sie->philo1->printf);
	printf("%s%lu%s %s%d%s %s%s%s\n", "\033[4;31m", get_time() - sie->philo1 \
			->start_time, "\033[0m", "\033[4;30m", sie->command, "\033[0m", \
			"\033[4;34m", str, "\033[0m");
	sem_post(sie->philo1->printf);
}
