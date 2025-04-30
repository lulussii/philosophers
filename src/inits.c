/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:58:19 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/30 15:47:32 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>
#include <string.h>

void	ft_pthread_mutex_init(pthread_mutex_t *mutex, t_all *all)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
		ft_error("Error: pthread_mutex_init failed\n", all);
}

void	init_philos(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->data->nbr_philos)
	{
		all->philos[i].all = all;
		all->philos[i].id = i + 1;
		all->philos[i].is_dead = 0;
		all->philos[i].forks[0] = 0;
		all->philos[i].forks[1] = 0;
		all->philos[i].data = all->data;
		all->philos[i].has_finished = 0;
		all->philos[i].last_meal = all->start_time;
		all->philos[i].meal_count = all->data->nbr_time_to_eat;
		all->philos[i].mutex_right_fork = &all->mutex_forks[i];
		all->philos[i].mutex_left_fork = &all->mutex_forks[(i + 1)
			% all->data->nbr_philos];
		ft_pthread_mutex_init(&all->philos[i].mutex_meal, all);
	}
}

void	*ft_malloc(int size, t_all *all)
{
	void *res = malloc(size);
	if (!res)
		ft_error("Error: malloc failed", all);
	return (res);
}

void	allocate_ressources(t_all *all)
{
	int	i;

	i = -1;
	all->forks = ft_malloc(sizeof(int) * all->data->nbr_philos, all);
	all->mutex_forks = ft_malloc(sizeof(pthread_mutex_t) * all->data->nbr_philos, all);
	while (++i < all->data->nbr_philos)
	{
		all->forks[i] = 0;
		ft_pthread_mutex_init(&all->mutex_forks[i], all);
	}
	all->philos = ft_malloc(sizeof(t_philo) * all->data->nbr_philos, all);
	all->threads = ft_malloc(sizeof(pthread_t) * all->data->nbr_philos, all);
	all->simulation_active = 1;
	all->max_meals = 0;
	ft_pthread_mutex_init(&all->simulation, all);
	ft_pthread_mutex_init(&all->print, all);
	ft_pthread_mutex_init(&all->mutex_max_meals, all);
	init_philos(all);
}
