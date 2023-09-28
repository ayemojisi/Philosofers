/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:35:40 by iergun            #+#    #+#             */
/*   Updated: 2023/09/28 00:33:43 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long	get_time(void)
{
	struct timeval	serkan;

	gettimeofday(&serkan, NULL);
	return (serkan.tv_sec * 1000 + serkan.tv_usec / 1000);
}

void	wait_time_for(long unsigned time, t_eternalend *sie)
{
	unsigned long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (check_death(sie) == 0)
			kill(getpid(), 15);
		usleep(100);
	}
}
