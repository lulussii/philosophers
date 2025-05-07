/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:38:23 by lulussi           #+#    #+#             */
/*   Updated: 2025/05/07 13:34:34 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

long	time_diff_ms(struct timeval t1)
{
	long			milliseconds;
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	milliseconds = ((actual.tv_sec * 1000 + actual.tv_usec / 1000) - (t1.tv_sec
				* 1000 + t1.tv_usec / 1000));
	return (milliseconds);
}

void	safe_print(t_philo *philos, char *task)
{
	pthread_mutex_lock(philos->all->print);
	pthread_mutex_lock(philos->all->simulation);
	if (philos->all->simulation_active && philos->meal_count != 0)
		printf("%li %i %s\n", time_diff_ms(philos->all->start_time), philos->id,
			task);
	pthread_mutex_unlock(philos->all->simulation);
	pthread_mutex_unlock(philos->all->print);
}

void	*ft_malloc(int size, t_all *all)
{
	void	*res;

	res = malloc(size);
	if (!res)
		ft_error("Error: malloc failed", all);
	return (res);
}

void	ft_pthread_mutex(pthread_mutex_t *mutex, t_philo *philos,
t_mutex_action action)
{
	if (action == LOCK)
	{
		if (pthread_mutex_lock(mutex))
			ft_error("Error: Mutex lock failed", philos->all);
	}
	else if (action == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex))
			ft_error("Error: Mutex unlock failed", philos->all);
	}
}
