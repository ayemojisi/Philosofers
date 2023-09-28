/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergun <iergun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:37:07 by iergun            #+#    #+#             */
/*   Updated: 2023/09/28 00:32:00 by iergun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <signal.h>

# define ERROR42 -1
# define MAX 2147483647

typedef struct s_eternalend
{
	int				command;
	int				count;
	int				is_eating;
	pid_t			id;
	struct s_philo	*philo1;
	unsigned long	start;
	unsigned long	eat_last;
}t_eternalend;

typedef struct s_philo
{
	sem_t			*forks;
	sem_t			*died;
	sem_t			*printf;
	int				total_philo;
	unsigned long	die_time;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	unsigned long	start_time;
	int				number1;
	int				died_philo;
	int				eat_count;
	t_eternalend	*eternald;
}t_philo;

int				ft_arg(int ac, char **av);
long long		ft_ato(const char *str);
t_philo			*philo_init(int ac, char **av);
t_philo			*philo_args_value(int ac, char **av, t_philo *philo);
void			wait_time_for(long unsigned time, t_eternalend *sie);
unsigned long	get_time(void);
t_eternalend	*eternald_info(t_philo *philo);
void			*proces(void *end);
int				check_death(t_eternalend *sie);
int				philo_fork(t_eternalend *eternalend, int total_philo);
int				philo_fork1(t_eternalend *eternalend, int total_philo);
void			eat(t_eternalend *sie);
void			philo_exit(t_philo *philo);
void			fork_printf(t_eternalend *sie, char *str);

#endif