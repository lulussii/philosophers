/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:04:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/08 21:00:03 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_error(char *str, t_all *all)
{
	ft_putstr(str);
	free(all);
	exit(1);
}

void	*routine(void *arg)
{
	t_philo *philos = (t_philo *)arg;
	printf("Je suis le philosphe n°:%i\n", philos->id);
	return (0);
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
		pthread_create(&all->threads[i], NULL, routine, &all->philos[i]);
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
	init_philos(all);
}
