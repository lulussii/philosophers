/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:08:30 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/07 14:41:05 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*monitor_philosophers(void *arg)
{
	t_all	*all;
	int		i;
	long	check_death;

	all = (t_all *)arg;
	check_death = 0;
	while (check_simulation_state(all))
	{
		i = -1;
		while (++i < all->data->nbr_philos)
		{
			pthread_mutex_lock(all->philos[i].mutex_meal);
			check_death = time_diff_ms(all->philos[i].last_meal);
			pthread_mutex_unlock(all->philos[i].mutex_meal);
			if (check_death > all->data->time_to_die)
			{
				safe_print(&all->philos[i], "died");
				stop_simulation(all);
			}
		}
		if (check_max_meals(all) == all->data->nbr_philos)
			stop_simulation(all);
		usleep(500);
	}
	return (NULL);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	if (philos->data->nbr_philos == 1)
	{
		single_philosopher_routine(philos);
		return (NULL);
	}
	if (philos->id % 2 == 0)
		usleep(philos->data->philosopher_eat * 100);
	while (check_simulation_state(philos->all))
	{
		philosopher_take_forks(philos);
		philosopher_eat(philos);
		philosopher_put_forks(philos);
		philosopher_sleep(philos);
		philosopher_think(philos);
	}
	return (NULL);
}

void	start_simulation(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->data->nbr_philos)
		pthread_create(&all->threads[i], NULL, philosopher_routine,
			&all->philos[i]);
	pthread_create(&all->monitor, NULL, monitor_philosophers, all);
	pthread_join(all->monitor, NULL);
	i = -1;
	while (++i < all->data->nbr_philos)
		pthread_join(all->threads[i], NULL);
}
