/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:16:03 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/08 20:58:44 by lserodon         ###   ########.fr       */
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

void	destroy_and_free_array(pthread_mutex_t *mutex_array, t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->data->nbr_philos)
		safe_mutex_destroy(&mutex_array[i], all);
	free(mutex_array);
}

void	cleanup_all_resources(t_all *all)
{
	destroy_all_mutexes(all);
	if (all->mutex_forks)
		destroy_and_free_array(all->mutex_forks, all);
	if (all->mutex_meal)
		destroy_and_free_array(all->mutex_meal, all);
	if (all->threads)
		free(all->threads);
	if (all->forks)
		free(all->forks);
	if (all->data)
		free(all->data);
	if (all->philos)
		free(all->philos);
	free(all);
}
