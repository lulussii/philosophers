/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:32:26 by lulussi           #+#    #+#             */
/*   Updated: 2025/04/09 18:01:30 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_forks(t_all *all)
{
    int i;

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
	all->philos = malloc(sizeof(t_philo) * all->data->nbr_philos);
	all->threads = malloc(sizeof(pthread_t) * all->data->nbr_philos);
	if (!all->philos || !all->threads)
		ft_error("Error\n", all);
	while (i < all->data->nbr_philos)
	{
		all->philos[i].id = i + 1;
		all->philos[i].data = all->data;
        init_forks(all);
		pthread_create(&all->threads[i], NULL, routine, &all->philos[i]);
		i++;
	}
}
