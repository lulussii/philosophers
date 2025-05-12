/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:58:19 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/12 10:30:36 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>
#include <string.h>

void	safe_mutex_init(pthread_mutex_t *mutex, t_all *all)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
		ft_error("Error: pthread_mutex_init failed", all);
}

void	init_philos(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->data->nbr_philos)
	{
		all->philos[i].all = all;
		all->philos[i].id = i + 1;
		all->philos[i].forks[0] = 0;
		all->philos[i].forks[1] = 0;
		all->philos[i].data = all->data;
		all->philos[i].last_meal = all->start_time;
		all->philos[i].meal_count = all->data->nbr_philosopher_eat;
		all->philos[i].mutex_right_fork = &all->mutex_forks[i];
		all->philos[i].mutex_left_fork = &all->mutex_forks[(i + 1)
			% all->data->nbr_philos];
		all->philos[i].mutex_meal = &all->mutex_meal[i];
	}
}

void	allocate_resources(t_all *all)
{
	int	i;

	i = -1;
	all->forks = ft_malloc(sizeof(int) * all->data->nbr_philos, all);
	all->mutex_forks = ft_malloc(sizeof(pthread_mutex_t)
			* all->data->nbr_philos, all);
	all->mutex_meal = ft_malloc(sizeof(pthread_mutex_t)
			* all->data->nbr_philos, all);
	while (++i < all->data->nbr_philos)
	{
		all->forks[i] = 0;
		safe_mutex_init(&all->mutex_forks[i], all);
		safe_mutex_init(&all->mutex_meal[i], all);
	}
	all->philos = ft_malloc(sizeof(t_philo) * all->data->nbr_philos, all);
	all->threads = ft_malloc(sizeof(pthread_t) * all->data->nbr_philos, all);
	all->simulation_active = 1;
	all->max_meals = 0;
	all->simulation = ft_malloc(sizeof(pthread_mutex_t), all);
	all->print = ft_malloc(sizeof(pthread_mutex_t), all);
	all->mutex_max_meals = ft_malloc(sizeof(pthread_mutex_t), all);
	safe_mutex_init(all->simulation, all);
	safe_mutex_init(all->print, all);
	safe_mutex_init(all->mutex_max_meals, all);
	init_philos(all);
}
