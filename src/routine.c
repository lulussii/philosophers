/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:25:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/10 14:32:24 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_forks(t_philo *philos)
{
	pthread_mutex_unlock(philos->right_fork);
	pthread_mutex_unlock(philos->left_fork);
}

void	time_to_eat(t_philo *philos)
{
	printf("Le philosophe n°%i est en train de manger\n", philos->id);
	usleep(philos->data->time_to_eat);
	put_forks(philos);
}

void	take_forks(t_philo *philos)
{
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->right_fork);
		printf("-- Philo n°%i a pris la fourchette droite n°%p\n", philos->id, philos->right_fork);
		pthread_mutex_lock(philos->left_fork);
		printf("-- Philo n°%i a pris la fourchette gauche n°%p\n", philos->id, philos->left_fork);
	}
	if (philos->id % 2 != 0)
	{
		pthread_mutex_lock(philos->left_fork);
		printf("-- Philo n°%i a pris la fourchette gauche n°%p\n", philos->id, philos->left_fork);
		pthread_mutex_lock(philos->right_fork);
		printf("-- Philo n°%i a pris la fourchette droite n°%p\n", philos->id, philos->right_fork);
	}
	time_to_eat(philos);
}

