/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:05:02 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/14 18:19:26 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ----- LIBRARIES ----- */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include "data.h"
#include "all.h"

/* ----- STRUCTURE ----- */

typedef struct s_philo
{
	int				id;
	int				is_dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*data;
	t_all			*all;
	long			last_meal;
}				t_philo;

/* ----- UTILS.C ----- */

int		ft_digit(char *str);
void	ft_putstr(char *str);
long	ft_atoi(char *str);

/* ----- PARSING.C ----- */

void	check_args(int argc, char **argv, t_all *all);
void	init_struct(int argc, char **argv, t_all *all);
void	check_values(t_all *all);

/* ----- PHILO.C ----- */

void	*routine(void *arg);
void	allocate_ressources(t_all *all);
long	timestamps(t_all *all);

/* ----- ERRORS.C ----- */

void	ft_error(char *str, t_all *all);

/* ----- INITS.C ----- */

void	init_forks(t_all *all);
void	init_philos(t_all *all);

/* ----- ROUTINE.C ----- */

void	take_forks(t_philo *philos);
void	time_to_eat(t_philo *philos);
void	put_forks(t_philo *philos);
void	time_to_sleep(t_philo *philos);
void	time_to_think(t_philo *philos);

#endif