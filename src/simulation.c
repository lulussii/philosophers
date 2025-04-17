/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:08:30 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/17 18:18:00 by lserodon         ###   ########.fr       */
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
	while (all->simulation_active)
	{
		i = 0;
		while (i < all->data->nbr_philos)
		{
			pthread_mutex_lock(&all->philos[i].meal_mutex);
			check_death = time_diff_ms(all->philos[i].last_meal);
			pthread_mutex_unlock(&all->philos[i].meal_mutex);
			if (check_death >= all->data->time_to_die)
			{
				safe_print(&all->philos[i], "died");
				all->simulation_active = 0;
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (philos->all->simulation_active)
	{
		if(philos->all->simulation_active)
			take_forks(philos);
		if(philos->all->simulation_active)
			time_to_eat(philos);
		if(philos->all->simulation_active)
			put_forks(philos);
		if(philos->all->simulation_active)
			time_to_sleep(philos);
		if(philos->all->simulation_active)
			time_to_think(philos);
	}
	return (NULL);
}

void	start_simulation(t_all *all)
{
	int	i;

	i = -1;
	init_philos(all);
	init_forks(all);
	while (++i < all->data->nbr_philos)
	{
		pthread_create(&all->threads[i], NULL, routine, &all->philos[i]);
		pthread_detach(all->threads[i]);
	}
	pthread_create(&all->monitor, NULL, check_last_meal, all);
	pthread_join(all->monitor, NULL);
}
