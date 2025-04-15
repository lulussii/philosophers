/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:32:26 by lulussi           #+#    #+#             */
/*   Updated: 2025/04/15 17:50:03 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
