/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:04:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/15 17:50:33 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_last_meal(void *arg)
{
	t_all	*all;
	int		i;
	long	check_death;

	all = (t_all *)arg;
	i = 0;
	check_death = 0;
	while (all->simulation_active)
	{
		while (i < all->data->nbr_philos)
		{
			pthread_mutex_lock(&all->philos[i].meal_mutex);
			check_death = time_diff_ms(all->philos[i].last_meal);
			pthread_mutex_unlock(&all->philos[i].meal_mutex);
			if (check_death <= 0)
			{
				printf("PHILO MORT\n");
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

long	time_diff_ms(struct timeval t1)
{
	long			milliseconds;
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	milliseconds = ((actual.tv_sec * 1000 + actual.tv_usec / 1000) - (t1.tv_sec
				* 1000 + t1.tv_usec / 1000));
	return (milliseconds);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	memset(all, 0, sizeof(t_all));
	all->simulation_active = 1;
	gettimeofday(&all->start_time, NULL);
	check_args(argc, argv, all);
	allocate_ressources(all);
	start_simulation(all);
	while (1)
		pause();
}
