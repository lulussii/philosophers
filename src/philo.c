/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:04:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/10 16:02:01 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philos = (t_philo *)arg;
	take_forks(philos);
	//printf("philo : %i, fourchette gauche %p, fourchette droite %p\n", philos->id, philos->left_fork, philos->right_fork);
	return (0);
}

void	allocate_ressources(t_all *all)
{
	int i;

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
	milliseconds = (actual.tv_sec - all->start_time) * 1000;
	
	return (milliseconds);
}

int	main(int argc, char **argv)
{
	t_all			*all;
	struct timeval	start;
	long			seconds;


	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	all->start_time = gettimeofday(&start, NULL);
	sleep(2);
	seconds = timestamps(all);
	printf("secondes %ld\n", seconds);
	check_args(argc, argv, all);
	allocate_ressources(all);
	//init_philos(all);
}
