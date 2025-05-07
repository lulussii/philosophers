/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:34:43 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/07 14:10:35 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "all.h"

typedef enum e_mutex_action
{
	LOCK,
	UNLOCK,
}	t_mutex_action;

/* ----- CLEANUP.C ----- */
void	safe_mutex_destroy(pthread_mutex_t *mutex, t_all *all);
void	destroy_all_mutexes(t_all *all);
void	cleanup_all_resources(t_all *all);
void	ft_error(char *str, t_all *all);

/* ----- INITS.C ----- */
void	init_philos(t_all *all);
void	allocate_resources(t_all *all);

/* ----- PARSING.C ----- */
void	init_data(int argc, char **argv, t_all *all);
void	check_values(t_all *all);
void	check_args(int argc, char **argv, t_all *all);

/* ----- ROUTINE.C ----- */
void	philosopher_think(t_philo *philos);
void	philosopher_sleep(t_philo *philos);
void	philosopher_put_forks(t_philo *philos);
void	philosopher_eat(t_philo *philos);
void	philosopher_take_forks(t_philo *philos);

/* ----- SIMULATION.C ----- */
int		check_max_meals(t_all *all);
int		check_simulation_state(t_all *all);
void	stop_simulation(t_all *all);
void	*monitor_philosophers(void *arg);
void	*philosopher_routine(void *arg);
void	start_simulation(t_all *all);
void	single_philosopher_routine(t_philo *philos);
void	ft_pthread_mutex(pthread_mutex_t *mutex, t_philo *philos,
			t_mutex_action action);

/* ----- UTILS.C ----- */
int		ft_digit(char *str);
void	ft_putstr(char *str);
long	ft_atoi(char *str);
long	time_diff_ms(struct timeval t1);
void	safe_print(t_philo *philos, char *task);
long	safe_atoi(char *str, t_all *all);
void	*ft_malloc(int size, t_all *all);

#endif