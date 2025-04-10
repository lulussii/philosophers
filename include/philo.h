/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:05:02 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/10 16:01:28 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ----- LIBRARIES ----- */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

/* ----- STRUCTURE ----- */

typedef struct s_data
{
	int			nbr_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_time_to_eat;
}				t_data;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*data;
}				t_philo;

typedef struct s_all
{
	long			start_time;
	t_data			*data;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
}				t_all;

/* ----- UTILS.C ----- */

int		ft_digit(char *str);
void	ft_putstr(char *str);
int		ft_atoi(char *str);

/* ----- PARSING.C ----- */

void	check_args(int argc, char **argv, t_all *all);
void	init_struct(int argc, char **argv, t_all *all);
void	check_values(t_all *all);

/* ----- PHILO.C ----- */

void	*routine(void *arg);
void	allocate_ressources(t_all *all);

/* ----- ERRORS.C ----- */

void	ft_error(char *str, t_all *all);

/* ----- INITS.C ----- */

void	init_forks(t_all *all);
void	init_philos(t_all *all);

/* ----- ROUTINE.C ----- */

void	take_forks(t_philo *philos);
void	time_to_eat(t_philo *philos);
void	put_forks(t_philo *philos);
