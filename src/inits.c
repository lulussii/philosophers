/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:58:19 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/16 16:09:16 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

void	init_forks(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->data->nbr_philos)
	{
		all->philos[i].right_fork = &all->forks[i];
		if (i == all->data->nbr_philos - 1)
			all->philos[i].left_fork = &all->forks[0];
		else
			all->philos[i].left_fork = &all->forks[i + 1];
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
		all->philos[i].data = all->data;
		all->philos[i].all = all;
		all->philos[i].last_meal = all->start_time;
		pthread_mutex_init(&all->philos[i].meal_mutex, NULL);
		i++;
	}
}

void	allocate_ressources(t_all *all)
{
	int	i;

	i = 0;
	all->philos = malloc(sizeof(t_philo) * all->data->nbr_philos);
	if (!all->philos)
		ft_error("Error\n", all);
	all->threads = malloc(sizeof(pthread_t) * all->data->nbr_philos);
	if (!all->threads)
		ft_error("Error\n", all);
	all->forks = malloc(sizeof(pthread_mutex_t) * all->data->nbr_philos);
	if (!all->forks)
		ft_error("Error\n", all);
	while (i < all->data->nbr_philos)
	{
		if (pthread_mutex_init(&all->forks[i], NULL) != 0)
			ft_error("Error\n", all);
		i++;
	}
}


