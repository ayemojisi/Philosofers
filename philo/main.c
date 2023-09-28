/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:56:13 by iergun            #+#    #+#             */
/*   Updated: 2023/09/23 00:46:30 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*death;
	t_philo			*philo;

	if (ft_arg(ac, av) == ERROR42)
	{
		printf("invalid argument");
		return (1);
	}
	philo = malloc(sizeof(*philo) * ft_ato(av[1]));
	forks = malloc(sizeof(pthread_mutex_t) * ft_ato(av[1]));
	death = malloc(sizeof(pthread_mutex_t));
	if (!philo || !forks || !death)
		return (ERROR42);
	ft_philo_i(philo, ac, av);
	create_mutex(philo, forks, death);
	ft_start_philo(philo, av);
	ft_free(philo, forks, death);
	return (0);
}
