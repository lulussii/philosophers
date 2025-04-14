/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:04:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/14 18:23:58 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death(t_philo	philo)
{
	struct timeval	actual;
	long			actual_time_in_ms;
	
	gettimeofday(&actual, NULL);	
	actual_time_in_ms = (actual.tv_sec * 1000) + (actual.tv_usec / 1000);
	if (actual_time_in_ms - all->philos)
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

long	timestamps(t_all *all)
{
	long			milliseconds;
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	milliseconds = ((actual.tv_sec * 1000 + actual.tv_usec / 1000)
			- (all->start_time.tv_sec * 1000 + all->start_time.tv_usec / 1000));
	return (milliseconds);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	memset(all, 0, sizeof(t_all));
	gettimeofday(&all->start_time, NULL);
	check_args(argc, argv, all);
	allocate_ressources(all);
	init_philos(all);
	while (1)
		pause();
}
