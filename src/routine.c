/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:25:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/15 17:50:09 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	time_to_think(t_philo *philos)
{
	printf("%li %i is thinking\n", time_diff_ms(philos->all->start_time),
		philos->id);
}

void	time_to_sleep(t_philo *philos)
{
	printf("%li %i is sleeping\n", time_diff_ms(philos->all->start_time),
		philos->id);
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
	printf("%li %i is eating\n", time_diff_ms(philos->all->start_time),
		philos->id);
	usleep(philos->data->time_to_eat * 1000);
}

void	take_forks(t_philo *philos)
{
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->right_fork);
		printf("%li %i has taken a fork\n",
			time_diff_ms(philos->all->start_time), philos->id);
		pthread_mutex_lock(philos->left_fork);
		printf("%li %i has taken a fork\n",
			time_diff_ms(philos->all->start_time), philos->id);
	}
	if (philos->id % 2 != 0)
	{
		pthread_mutex_lock(philos->left_fork);
		printf("%li %i has taken a fork\n",
			time_diff_ms(philos->all->start_time), philos->id);
		pthread_mutex_lock(philos->right_fork);
		printf("%li %i has taken a fork\n",
			time_diff_ms(philos->all->start_time), philos->id);
	}
}
