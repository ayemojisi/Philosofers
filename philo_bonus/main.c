/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:28:20 by iergun            #+#    #+#             */
/*   Updated: 2023/09/21 16:49:58 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ft_arg(ac, av) == ERROR42)
	{
		printf("invalid argument");
		return (1);
	}
	philo = philo_init(ac, av);
	philo_exit(philo);
	return (0);
}
