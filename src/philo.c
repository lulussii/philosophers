/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:04:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/09 18:01:47 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philos)
{
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->right_fork);
		printf("-- Philo n°%i a pris la fourchette droite n°%p\n", philos->id, philos->right_fork);
		pthread_mutex_lock(philos->left_fork);
		printf("-- Philo n°%i a pris la fourchette gauche n°%p\n", philos->id, philos->left_fork);
	}
	if (philos->id % 2 != 0)
	{
		pthread_mutex_lock(philos->left_fork);
		printf("-- Philo n°%i a pris la fourchette gauche n°%p\n", philos->id, philos->left_fork);
		pthread_mutex_lock(philos->right_fork);
		printf("-- Philo n°%i a pris la fourchette droite n°%p\n", philos->id, philos->right_fork);
	}
	printf("Le philosophe n°%i est en train de manger\n", philos->id);
}

void	*routine(void *arg)
{
	t_philo *philos = (t_philo *)arg;
	take_forks(philos);
	//printf("philo : %i, fourchette gauche %p, fourchette droite %p\n", philos->id, philos->left_fork, philos->right_fork);
	usleep(100);
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

int	main(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	check_args(argc, argv, all);
	allocate_ressources(all);
	init_philos(all);
}
