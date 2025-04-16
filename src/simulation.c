/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:08:30 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/16 16:46:35 by lserodon         ###   ########.fr       */
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
				free_all(all);
				exit(1);
			}
			i++;
		}
		usleep(1000);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (!philos->is_dead)
	{
		take_forks(philos);
		time_to_eat(philos);
		put_forks(philos);
		time_to_sleep(philos);
		time_to_think(philos);
	}
	return (0);
}

void	start_simulation(t_all *all)
{
	int	i;

	i = -1;
	all->philos = malloc(sizeof(t_philo) * all->data->nbr_philos);
	all->threads = malloc(sizeof(pthread_t) * all->data->nbr_philos);
	if (!all->philos || !all->threads)
		ft_error("Error\n", all);
	init_philos(all);
	init_forks(all);
	while (++i < all->data->nbr_philos)
		pthread_create(&all->threads[i], NULL, routine, &all->philos[i]);
	pthread_create(&all->monitor, NULL, check_last_meal, all);
}