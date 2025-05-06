/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:25:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/05 10:47:41 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <unistd.h>

void	time_to_think(t_philo *philos)
{
	safe_print(philos, "is thinking");
	usleep(500);
}

void	time_to_sleep(t_philo *philos)
{
	safe_print(philos, "is sleeping");
	usleep(philos->data->time_to_sleep * 1000);
}

void	put_forks(t_philo *philos)
{
	philos->forks[0] = 0;
	philos->forks[1] = 0;
	ft_pthread_mutex(philos->mutex_right_fork, philos, UNLOCK);
	ft_pthread_mutex(philos->mutex_left_fork, philos, UNLOCK);
}

void	time_to_eat(t_philo *philos)
{
	pthread_mutex_lock(&philos->mutex_meal);
	gettimeofday(&philos->last_meal, NULL);
	pthread_mutex_unlock(&philos->mutex_meal);
	safe_print(philos, "is eating");
	if (philos->data->nbr_time_to_eat > -1)
	{
		philos->meal_count--;
		if (philos->meal_count == 0)
		{
			pthread_mutex_lock(&philos->all->mutex_max_meals);
			philos->all->max_meals++;
			pthread_mutex_unlock(&philos->all->mutex_max_meals);
		}
	}
	usleep(philos->data->time_to_eat * 1000);
}

void	take_forks(t_philo *philos)
{
	if (philos->mutex_left_fork < philos->mutex_right_fork)
	{
		ft_pthread_mutex(philos->mutex_left_fork, philos, LOCK);
		ft_pthread_mutex(philos->mutex_right_fork, philos, LOCK);
	}
	else
	{
		ft_pthread_mutex(philos->mutex_right_fork, philos, LOCK);
		ft_pthread_mutex(philos->mutex_left_fork, philos, LOCK);
	}
	philos->forks[0] = 1;
	philos->forks[1] = 1;
	safe_print(philos, "has taken a fork");
	safe_print(philos, "has taken a fork");
}
