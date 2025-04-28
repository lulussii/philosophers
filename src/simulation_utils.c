/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:00:20 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/28 14:57:14 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <unistd.h>

int	check_max_meals(t_all *all)
{
	int	meals;

	pthread_mutex_lock(&all->mutex_max_meals);
	meals = all->max_meals;
	pthread_mutex_unlock(&all->mutex_max_meals);
	return (meals);
}

int	check_simulation_state(t_all *all)
{
	int	is_active;

	pthread_mutex_lock(&all->simulation);
	is_active = all->simulation_active;
	pthread_mutex_unlock(&all->simulation);
	return (is_active);
}

void	stop_simulation(t_all *all)
{
	pthread_mutex_lock(&all->simulation);
	all->simulation_active = 0;
	pthread_mutex_unlock(&all->simulation);
}

void	small_routine(t_philo *philos)
{
	safe_print(philos, "has taken a fork");
	usleep(philos->data->time_to_die * 1000);
}

void	set_forks_order(t_philo *philos)
{
	if (philos->mutex_left_fork < philos->mutex_right_fork)
	{
		philos->forks.first_mutex = philos->mutex_left_fork;
		philos->forks.second_mutex = philos->mutex_right_fork;
		philos->forks.first_fork = philos->left_fork;
		philos->forks.second_fork = philos->right_fork;
	}
	else
	{
		philos->forks.first_mutex = philos->mutex_right_fork;
		philos->forks.second_mutex = philos->mutex_left_fork;
		philos->forks.first_fork = philos->right_fork;
		philos->forks.second_fork = philos->left_fork;
	}
}
