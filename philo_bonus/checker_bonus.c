/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:33:36 by iergun            #+#    #+#             */
/*   Updated: 2023/09/28 01:20:32 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_death(t_eternalend *sie)
{
	if (((get_time() - sie->eat_last) >= sie->philo1->die_time))
	{
		sem_wait(sie->philo1->printf);
		usleep(1000);
		printf("%s%lu %d %s%s\n", "\033[1;31m", \
		get_time() - sie->philo1->start_time \
		, sie->command, "is died", "\033[0m");
		return (0);
	}
	if (sie->philo1->die_time < sie->philo1->eat_time \
		&& get_time() - sie->philo1->start_time >= sie->philo1->die_time)
	{
		printf("%s%lu %d %s%s\n", "\033[1;31m", get_time() - sie \
		->philo1->start_time, sie->command, "is died", "\033[0m");
		return (0);
	}
	return (1);
}
