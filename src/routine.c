/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:25:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/23 12:51:05 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <unistd.h>

void	time_to_think(t_philo *philos)
{
	safe_print(philos, "is thinking");
}

void	time_to_sleep(t_philo *philos)
{
	safe_print(philos, "is sleeping");
	usleep(philos->data->time_to_sleep * 1000);
}

void	put_forks(t_philo *philos)
{
	pthread_mutex_unlock(philos->right_fork);
	pthread_mutex_unlock(philos->left_fork);
}

void	time_to_eat(t_philo *philos)
{
	pthread_mutex_lock(&philos->meal_mutex);
	gettimeofday(&philos->last_meal, NULL);
	pthread_mutex_unlock(&philos->meal_mutex);
	safe_print(philos, "is eating");
	if (philos->data->nbr_time_to_eat > -1)
	{
		philos->meal_count--;
		if (philos->meal_count == 0)
		{	
			pthread_mutex_lock(&philos->all->mutex_max_meals);
			philos->all->max_meals++;
			printf("%i\n", philos->all->max_meals);
			pthread_mutex_unlock(&philos->all->mutex_max_meals);
		}
	}
	usleep(philos->data->time_to_eat * 1000);
}

void	take_forks(t_philo *philos)
{
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->right_fork);
		safe_print(philos, "has taken a fork");
		pthread_mutex_lock(philos->left_fork);
		safe_print(philos, "has taken a fork");
	}
	if (philos->id % 2 != 0)
	{
		pthread_mutex_lock(philos->left_fork);
		safe_print(philos, "has taken a fork");
		pthread_mutex_lock(philos->right_fork);
		safe_print(philos, "has taken a fork");
	}
}
