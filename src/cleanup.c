/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:16:03 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/12 10:19:51 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void	safe_mutex_destroy(pthread_mutex_t *mutex, t_all *all)
{
	if (pthread_mutex_destroy(mutex) != 0)
		ft_error("Error : Destroy mutex failed", all);
}

void	destroy_all_mutexes(t_all *all)
{
	if (all->simulation)
	{
		safe_mutex_destroy(all->simulation, all);
		free(all->simulation);
	}
	if (all->print)
	{
		safe_mutex_destroy(all->print, all);
		free(all->print);
	}
	if (all->mutex_max_meals)
	{
		safe_mutex_destroy(all->mutex_max_meals, all);
		free(all->mutex_max_meals);
	}
}

void	free_philos(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->data->nbr_philos)
	{
		if (all->philos[i].mutex_meal)
		{
			safe_mutex_destroy(all->philos[i].mutex_meal, all);
			free(all->philos[i].mutex_meal);
		}
	}
	free(all->philos);
}

void	cleanup_all_resources(t_all *all)
{
	int	i;

	i = -1;
	destroy_all_mutexes(all);
	if (all->mutex_forks)
	{
		while (++i < all->data->nbr_philos)
		{
			safe_mutex_destroy(&all->mutex_forks[i], all);
		}
		free(all->mutex_forks);
	}
	if (all->threads)
		free(all->threads);
	if (all->forks)
		free(all->forks);
	if (all->philos)
		free_philos(all);
	if (all->data)
		free(all->data);
	free(all);
}
