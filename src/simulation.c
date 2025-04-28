/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:08:30 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/28 17:36:20 by lserodon         ###   ########.fr       */
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
			pthread_mutex_lock(&all->philos[i].meal_mutex);
			check_death = time_diff_ms(all->philos[i].last_meal);
			pthread_mutex_unlock(&all->philos[i].meal_mutex);
			if (check_death >= all->data->time_to_die)
			{
				safe_print(&all->philos[i], "died");
				stop_simulation(all);
			}
			if (check_max_meals(all) == all->data->nbr_philos)
				stop_simulation(all);
		}
		usleep(1500);
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
	while (check_simulation_state(philos->all))
	{
		take_forks(philos);
		time_to_eat(philos);
		put_forks(philos);
		time_to_sleep(philos);
		time_to_think(philos);	
	}
	if (philos->meal_count == 0)
		return (NULL);
	return (NULL);
}

void	start_simulation(t_all *all)
{
	int	i;

	i = -1;
	init_philos(all);
	init_forks(all);
	while (++i < all->data->nbr_philos)
		pthread_create(&all->threads[i], NULL, routine, &all->philos[i]);
	pthread_create(&all->monitor, NULL, check_last_meal, all);
	pthread_join(all->monitor, NULL);
	i = -1;
	while (++i < all->data->nbr_philos)
		pthread_join(all->threads[i], NULL);
}
