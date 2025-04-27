/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:25:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/27 22:59:13 by lulussi          ###   ########.fr       */
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
	pthread_mutex_lock(philos->mutex_right_fork);
	pthread_mutex_lock(philos->mutex_left_fork);
	*(philos->right_fork) = 0;
	*(philos->left_fork) = 0;
	pthread_mutex_unlock(philos->mutex_left_fork);
	pthread_mutex_unlock(philos->mutex_right_fork);
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
			pthread_mutex_unlock(&philos->all->mutex_max_meals);
		}
	}
	usleep(philos->data->time_to_eat * 1000);
}

void take_forks(t_philo *philos)
{
    int forks_taken = 0;

    while (!forks_taken)
    {
        pthread_mutex_lock(philos->mutex_right_fork);
        pthread_mutex_lock(philos->mutex_left_fork);

        if (*(philos->right_fork) == 0 && *(philos->left_fork) == 0)
        {
            *(philos->right_fork) = 1;
            *(philos->left_fork) = 1;
            safe_print(philos, "has taken a fork");
            safe_print(philos, "has taken a fork");
            forks_taken = 1;
        }
        pthread_mutex_unlock(philos->mutex_left_fork);
        pthread_mutex_unlock(philos->mutex_right_fork);

        if (!forks_taken)
            usleep(100);
    }
}
