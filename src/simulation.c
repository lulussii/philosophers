/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:08:30 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/30 14:45:36 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*check_last_meal(void *arg)
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
			pthread_mutex_lock(&all->philos[i].mutex_meal);
			check_death = time_diff_ms(all->philos[i].last_meal);
			pthread_mutex_unlock(&all->philos[i].mutex_meal);
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

void	*routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	if (philos->data->nbr_philos == 1)
	{
		small_routine(philos);
		return (NULL);
	}
	if (philos->id % 2 == 0)
		usleep(philos->data->time_to_eat * 100);
	while (check_simulation_state(philos->all))
	{
		take_forks(philos);
		time_to_eat(philos);
		put_forks(philos);
		time_to_sleep(philos);
		time_to_think(philos);	
	}
	return (NULL);
}

void	start_simulation(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->data->nbr_philos)
		pthread_create(&all->threads[i], NULL, routine, &all->philos[i]);
	pthread_create(&all->monitor, NULL, check_last_meal, all);
	pthread_join(all->monitor, NULL);
	i = -1;
	while (++i < all->data->nbr_philos)
		pthread_join(all->threads[i], NULL);
}
