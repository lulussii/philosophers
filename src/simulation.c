/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:08:30 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/27 16:31:33 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	check_max_meals(t_all *all)
{
	int	meals;

	pthread_mutex_lock(&all->mutex_max_meals);
	meals = all->max_meals;
	pthread_mutex_unlock(&all->mutex_max_meals);

	return (meals);
}

int	check_simulation_state(t_all *all)
{
	int	is_active;

	pthread_mutex_lock(&all->simulation);
	is_active = all->simulation_active;
	pthread_mutex_unlock(&all->simulation);
	return (is_active);
}

void	stop_simulation(t_all *all)
{
	pthread_mutex_lock(&all->simulation);
	all->simulation_active = 0;
	pthread_mutex_unlock(&all->simulation);
}

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
			{	
				pthread_mutex_lock(&all->print);
				stop_simulation(all);
				pthread_mutex_unlock(&all->print);
			}
		}
		usleep(1500);
	}
	return (NULL);
}

void	small_routine(t_philo *philos)
{
	safe_print(philos, "has taken a fork");
	usleep(philos->data->time_to_die * 1000);
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
