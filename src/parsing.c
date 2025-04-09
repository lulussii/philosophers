/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:55:50 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/09 10:16:44 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int argc, char **argv, t_all *all)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		ft_error("Error: Wrong number of arguments\n", all);
	while (i < argc)
	{
		if (!ft_digit(argv[i]))
			ft_error("Error : Wrong type of arguments\n", all);
		i++;
	}
	init_struct(argc, argv, all);
	check_values(all);
}

void	init_struct(int argc, char **argv, t_all *all)
{
	all->data = malloc(sizeof(t_data));
	if (!all->data)
		ft_error("Error\n", all);
	all->data->nbr_philos = ft_atoi(argv[1]);
	all->data->time_to_die = ft_atoi(argv[2]);
	all->data->time_to_eat = ft_atoi(argv[3]);
	all->data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		all->data->nbr_time_to_eat = ft_atoi(argv[5]);
	else
		all->data->nbr_time_to_eat = -1;
}

void	check_values(t_all *all)
{
	if (!all->data->nbr_philos)
		ft_error("Error: The number of philosophers cannot be 0.\n", all);
	if (!all->data->time_to_die)
		ft_error("Error: The time to die cannot be 0.\n", all);
	if (!all->data->time_to_eat)
		ft_error("Error: The time to eat cannot be 0.\n", all);
	if (!all->data->time_to_sleep)
		ft_error("Error: The time to sleep cannot be 0.\n", all);
	if (!all->data->nbr_time_to_eat)
		ft_error("Error:  The number of times a philosopher must eat cannot be 0.\n",
			all);
}
