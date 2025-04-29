/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:58:19 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/29 17:24:52 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>
#include <string.h>

void	init_forks(t_all *all)
{
	int	i;

	i = 0;
	all->mutex_forks = malloc(sizeof(pthread_mutex_t) * all->data->nbr_philos);
	if (!all->mutex_forks)
		ft_error("Error\n", all);
	while (i < all->data->nbr_philos)
	{
		if (pthread_mutex_init(&all->mutex_forks[i], NULL) != 0)
			ft_error("Error\n", all);
		i++;
	}
	i = 0;
	while (i < all->data->nbr_philos)
	{
		all->philos[i].mutex_right_fork = &all->mutex_forks[i];
		all->philos[i].mutex_left_fork = &all->mutex_forks[(i + 1)
			% all->data->nbr_philos];
		all->philos[i].right_fork = &all->forks[i];
		all->philos[i].left_fork = &all->forks[(i + 1) % all->data->nbr_philos];
		i++;
	}
}

void	init_philos(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data->nbr_philos)
	{
		all->philos[i].id = i + 1;
		all->philos[i].is_dead = 0;
		all->philos[i].has_finished = 0;
		all->philos[i].data = all->data;
		all->philos[i].all = all;
		all->philos[i].last_meal = all->start_time;
		if (pthread_mutex_init(&all->philos[i].meal_mutex, NULL) != 0)
			ft_error("Error\n", all);
		all->philos[i].meal_count = all->data->nbr_time_to_eat;
		i++;
	}
}

void	allocate_ressources(t_all *all)
{
	int	i;

	i = -1;
	all->forks = malloc(sizeof(int) * all->data->nbr_philos);
	if (!all->forks)
		ft_error("Error\n", all);
	while (++i < all->data->nbr_philos)
		all->forks[i] = 0;
	all->philos = malloc(sizeof(t_philo) * all->data->nbr_philos);
	if (!all->philos)
		ft_error("Error\n", all);
	all->threads = malloc(sizeof(pthread_t) * all->data->nbr_philos);
	if (!all->threads)
		ft_error("Error\n", all);
	all->simulation_active = 1;
	all->max_meals = 0;
	if (pthread_mutex_init(&all->simulation, NULL) != 0
		|| pthread_mutex_init(&all->print, NULL) != 0
		|| pthread_mutex_init(&all->print, NULL) != 0)
		ft_error("Error\n", all);
}
